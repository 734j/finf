#include <stdio.h>
#include <stdlib.h>
#include "finf.h"
#include <string.h>

void finf(char search[], char filename[]) {
    int i = 0, k = 0;
    size_t searchsz = strlen(search);
    int startindex = 0;
    int findcount = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);

    while (startindex != filesize) { // Update the condition here

        char temp[searchsz];
        int foundflag = 0;

        fseek(file, startindex, SEEK_SET);

        for (i = 0 ; i < searchsz ; i++) {
            char ch = fgetc(file);
            if (ch == EOF)
                break;
            temp[i] = ch;
        }

        for (k = 0; k < searchsz; k++) {
            if (temp[k] == search[k]) {
                foundflag++;
                if (foundflag == searchsz) {
                    findcount++;
                    printf("Word found.\n");
                }
            } else {
                break;
            }
        }
        startindex++;
    }

    printf("The string or character \"");
    for (int m = 0; m < searchsz; m++) {
        printf("%c", search[m]);
    }
    printf("\" was found %d times.\n", findcount);

    fclose(file);
}

