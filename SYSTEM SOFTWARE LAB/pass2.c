#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if opcode exists in OPTAB
int searchOpcode(char op[]) {
    FILE *fop = fopen("optab.txt","r");
    if(!fop) { printf("Error: Cannot open optab.txt\n"); exit(1); }

    char line[100], opcode[20];
    int value;
    while(fgets(line,sizeof(line),fop)) {
        sscanf(line,"%s %x",opcode,&value);  // read hex value
        if(strcmp(op,opcode)==0) {
            fclose(fop);
            return 1;
        }
    }
    fclose(fop);
    return 0;
}

// Get object code from OPTAB + SYMTAB
char* getObjectCode(char op[], char opera[]) {
    static char objcode[10];
    FILE *fop = fopen("optab.txt","r");
    if(!fop) { printf("Error: Cannot open optab.txt\n"); exit(1); }

    char line[100], opcode[20];
    int value;
    while(fgets(line,sizeof(line),fop)) {
        sscanf(line,"%s %x",opcode,&value);
        if(strcmp(opcode, op) == 0) break;
    }
    fclose(fop);

    FILE *fsym = fopen("symtab.txt","r");
    if(!fsym) { printf("Error: Cannot open symtab.txt\n"); exit(1); }

    char operand[20];
    int addr;
    while(fgets(line,sizeof(line),fsym)) {
        sscanf(line,"%s %x",operand,&addr);  // symbol addresses in hex
        if(strcmp(operand, opera) == 0) break;
    }
    fclose(fsym);

    sprintf(objcode, "%02X%04X", value, addr);  // hex formatting
    return objcode;
}

int main() {
    FILE *fint = fopen("intermediate.txt","r");
    FILE *fout = fopen("output.txt","w");
    FILE *flen = fopen("length.txt","r");
    if(!fint || !fout || !flen) { printf("File missing\n"); return 1; }

    int programLength = 0;
    char line[100], len[10];
    while(fgets(len,sizeof(len),flen)) programLength = strtol(len, NULL, 16);  // hex

    int sa = 0;          // starting address
    char textRecord[1000] = "";
    int textLen = 0;
    int textStart = 0;

    while(fgets(line,sizeof(line),fint)) {
        char label[20], opcode[20], operand[20];
        int addr;
        int items = sscanf(line,"%X %s %s %s", &addr, label, opcode, operand);

        char objcode[20] = "";

        if(strcmp(opcode,"START")==0) {
            sa = addr;
            fprintf(fout,"H^%s^%06X^%06X\n", label, addr, programLength);
            textStart = addr;
            textLen = 0;
            textRecord[0] = '\0';
            continue;
        }

        if(strcmp(opcode,"END")!=0) {
            if(strcmp(label,".")!=0) {  // ignore comments
                if(searchOpcode(opcode)) {
                    strcpy(objcode, getObjectCode(opcode, operand));
                } 
                else if(strcmp(opcode,"BYTE")==0) {
                    if(operand[0]=='C') {  // e.g., C'EOF'
                        objcode[0] = '\0';
                        for(int i=2; operand[i]!='\''; i++) {
                            char temp[3];
                            sprintf(temp,"%02X", (unsigned char)operand[i]);
                            strcat(objcode,temp);
                        }
                    } 
                    else if(operand[0]=='X') {  // e.g., X'F1'
                        strncpy(objcode, operand+2, strlen(operand)-3);
                        objcode[strlen(operand)-3]='\0';
                    }
                } 
                else if(strcmp(opcode,"WORD")==0) {
                    int val = atoi(operand);
                    sprintf(objcode,"%06X", val);  // hex
                } 
                else if(strcmp(opcode,"RESW")==0 || strcmp(opcode,"RESB")==0) {
                    if(textLen>0) {
                        fprintf(fout,"T^%06X^%02X^%s\n", textStart, textLen, textRecord);
                        textLen = 0; textRecord[0]='\0';
                    }
                    continue;
                }
            }

            // Append to text record
            if(objcode[0]!='\0') {
                if(textLen + (strlen(objcode)/2) > 30) {  // max 30 bytes
                    fprintf(fout,"T^%06X^%02X^%s\n", textStart, textLen, textRecord);
                    textStart = addr; textLen=0; textRecord[0]='\0';
                }
                if(textLen>0) strcat(textRecord,"^");
                strcat(textRecord,objcode);
                textLen += strlen(objcode)/2;
            }
        } 
        else { // END
            if(textLen>0)
                fprintf(fout,"T^%06X^%02X^%s\n", textStart, textLen, textRecord);
            fprintf(fout,"E^%06X\n", sa);
            break;
        }
    }

    fclose(fint); fclose(fout); fclose(flen);

    // Display output
    fout = fopen("output.txt","r");
    while(fgets(line,sizeof(line),fout)) printf("%s",line);
    fclose(fout);

    return 0;
}
