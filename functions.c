#include <stdio.h>
#include <stdlib.h>
#include "finf.h"
#include <string.h>

void finf(char search[], char filename[]) {
    int /*i = 0,*/k = 0;
    size_t searchsz = strlen(search); // size of the search string
    int startindex = 0;
    int findcount = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);

    while (startindex != filesize) { //keeps looping until startindex equals to the filesize

        int foundflag = 0;

        fseek(file, startindex, SEEK_SET);


        for (k = 0; k < searchsz; k++) {
        	
	char ch = fgetc(file);
	if (ch == EOF)
	    break;
		
	if (ch == search[k]) {
            foundflag++;
               
	if (foundflag == searchsz) {
            findcount++;
            printf("Word found.\n");
		// print the line where word was found
		// do the logic here
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

