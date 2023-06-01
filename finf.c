#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "finf.h"

#define USAGE "Usage: [-h] [-f string]\n"  


int main(int argc, char *argv[])
{


    int opt;
    int cnt = 0;
    while ((opt = getopt(argc, argv, "hf:")) != -1){
        cnt++;
        if(cnt > 1) {
            printf("Only 1 argument at a time!\n");
            return EXIT_FAILURE;
        }
    }
    optind = 0;
    
    while ((opt = getopt(argc, argv, "hf:")) != -1) {
        switch (opt) {
        case 'h':
        
            printf("%s", USAGE);
            break;

        case 'f':
            
            finf(optarg);
            break;

        default: 
            fprintf(stderr, "%s", USAGE);
            return EXIT_FAILURE;
        }
    }

    if (argc == 1) {
        printf("%s", USAGE);
    }


    return EXIT_SUCCESS;

}