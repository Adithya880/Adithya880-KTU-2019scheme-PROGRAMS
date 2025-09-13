#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int locctr;

// Search OPTAB for opcode
void search(char op[], char operand[]) {
    FILE *fop;
    char opcode[20];
    int value, found = 0;

    fop = fopen("optab.txt", "r");
    if (!fop) {
        printf("Error opening optab.txt\n");
        return;
    }

    while (fscanf(fop, "%s %d", opcode, &value) != EOF) {
        if (strcmp(opcode, op) == 0) {
            locctr += 3; // all instructions 3 bytes
            found = 1;
            break;
        }
    }
    fclose(fop);

    if (!found) {
        if (strcmp(op, "WORD") == 0) locctr += 3;
        else if (strcmp(op, "RESW") == 0) locctr += 3 * strtol(operand, NULL, 16);
        else if (strcmp(op, "RESB") == 0) locctr += strtol(operand, NULL, 16);
        else if (strcmp(op, "BYTE") == 0) {
            int len = 0;
            if (operand[0] == 'C') len = strlen(operand) - 3;       // C'EOF' → 3 bytes
            else if (operand[0] == 'X') len = (strlen(operand) - 3) / 2; // X'F1' → 1 byte
            locctr += len;
        }
        else {
            printf("\nOpcode error: %s", op);
        }
    }
}

// Search SYMTAB for duplicate symbols
int searchSym(char lab[]) {
    FILE *fsym;
    char label[20];
    int found = 0, addr;

    fsym = fopen("symtab.txt", "a+");
    if (!fsym) {
        printf("Error opening symtab.txt\n");
        return 0;
    }

    rewind(fsym);
    while (fscanf(fsym, "%s %x", label, &addr) != EOF) { // read hex addresses
        if (strcmp(label, lab) == 0) {
            found = 1;
            break;
        }
    }

    if (!found)
        fprintf(fsym, "%s %04X\n", lab, locctr); // write hex addresses

    fclose(fsym);
    return found;
}

int main() {
    FILE *fin, *fint, *flen;
    char line[100], label[20], opcode[20], operand[20];
    int count, sa, length;

    fin = fopen("input.txt", "r");
    fint = fopen("intermediate.txt", "w");
    if (!fin || !fint) {
        printf("Error opening input or intermediate file\n");
        return 1;
    }

    locctr = 0;

    while (fgets(line, sizeof(line), fin)) {
        count = sscanf(line, "%s %s %s", label, opcode, operand);

        if (strcmp(opcode, "START") == 0) {
            locctr = (int)strtol(operand, NULL, 16); // hex start address
            sa = locctr;
            fprintf(fint, "%04X %s %s %s\n", sa, label, opcode, operand);
        } else {
            if (strcmp(label, "-") != 0) {
                if (searchSym(label))
                    printf("\nError: Duplicate symbol %s", label);
            }
            fprintf(fint, "%04X %s", locctr, line);
            search(opcode, operand);
        }
    }

    length = locctr - sa;
    flen = fopen("length.txt", "w");
    fprintf(flen, "%06X", length); // write length in hex
    fclose(flen);

    fclose(fint);
    fclose(fin);

    printf("\nPass 1 completed. Program length: %06X\n", length);
    return 0;
}
