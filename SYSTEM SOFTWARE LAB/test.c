#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in = fopen("test.txt", "r");
    FILE *out = fopen("sample.txt", "w");

    if (!in || !out) {
        printf("Error opening file!\n");
        return 1;
    }

    char str[50];
    while (fscanf(in, "%s", str) == 1) {
        // Convert string (hex) → decimal
        long value = strtol(str, NULL, 16);

        // Perform addition
        value += 3;

        // Write back in HEX to output file
        fprintf(out, "%X\n", (int)value);
    }

    fclose(in);
    fclose(out);
    return 0;
}
