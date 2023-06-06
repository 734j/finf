#include <stdio.h>
#include <stdlib.h>
#include "finf.h"
#include <string.h>

void finf (char search[]) { // First version of finf. VERY BAD. 
    int i = 0, k = 0;
    size_t searchsz = strlen(search);
    int startindex = 0;
    int findcount = 0;
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fseek(file, 0, SEEK_END); 
    long filesize = ftell(file); // Determine the amound of characters in a file. 
    
    while (startindex != filesize) {

        char temp[searchsz];
        int foundflag = 0;

        fseek(file, startindex, SEEK_SET); // startindex

        for (i = 0 ; i < searchsz ; i++) { // Assign first searchsz letters of contacts.txt to temp
            char ch = fgetc(file);
            if (ch == EOF)
                break;
            temp[i] = ch;

        }

        for (k = 0; k < searchsz; k++){ // Compare temp and search
                if (temp[k] == search[k]) {
                    foundflag++;
                    if (foundflag == searchsz) {
                        findcount++;
                        printf("Word found.\n");   
                    } // Check if the word is found or not. If the foundflag = searchsz then the word was found. 
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
