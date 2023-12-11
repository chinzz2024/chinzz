#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char opcode[10], operand[10], label[10], code[10], mnemonic[10];
    int locctr, start, length;
    FILE *f1, *f2, *f3, *f4, *f5, *f6;

    f1 = fopen("input.txt", "r");
    f2 = fopen("optab.txt", "r");
    f3 = fopen("symtab.txt", "w");
    f4 = fopen("inter.txt", "w");
    f5 = fopen("length.txt", "w");
    f6 = fopen("start.txt", "w");

    if (f1 == NULL || f2 == NULL || f3 == NULL || f4 == NULL || f5 == NULL || f6 == NULL) {
        printf("Error opening one or more files.\n");
        exit(1);
    }

    fscanf(f1, "%s %s %s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        start = atoi(operand);
        locctr = start;
        fprintf(f4, "\t%s %s %s\n", label, opcode, operand);
        fscanf(f1, " %s %s %s", label, opcode, operand);
    } else {
        locctr = 0;
    }

    fprintf(f6, "%d", start);

    while (strcmp(opcode, "END") != 0) {
        fprintf(f4, "%d\t", locctr);

        if (strcmp(label, "*") != 0) {
            fprintf(f3, "%s\t%d\n", label, locctr);
        }

        rewind(f2);
        fscanf(f2, "%s %s", code, mnemonic);

        while (strcmp(code, "END") != 0) {
            if (strcmp(opcode, code) == 0) {
                locctr += 3;
                break;
            }
            fscanf(f2, "%s %s", code, mnemonic);
        }

        if (strcmp(opcode, "WORD") == 0) {
            locctr += 3;
        }

        if (strcmp(opcode, "RESW") == 0) {
            locctr += 3 * atoi(operand);
        }

        if (strcmp(opcode, "RESB") == 0) {
            locctr += atoi(operand);
        }

        if (strcmp(opcode, "BYTE") == 0) {
            locctr++;
        }

        fprintf(f4, " %s %s %s\n", label, opcode, operand);
        length = locctr - start;

        fprintf(f5, "%d", length);

        fscanf(f1, " %s %s %s", label, opcode, operand);
    }
        printf("The length of code: %d\n", length);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
}

