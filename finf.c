#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "finf.h"

#define USAGE "Usage: [-h] [-s string] [-f file]\n"  


int main(int argc, char *argv[])
{
    char *file = NULL;
    char *string = NULL;
    int opt;
    int f_req = 0;
    int s_req = 0;
    
    while ((opt = getopt(argc, argv, "hs:f:")) != -1) {
        switch (opt) {
        case 'h':
        
            printf("%s", USAGE);
	    return EXIT_SUCCESS;
            break;
	
	case 'f':
	    file = malloc(strlen(optarg) + 1);
	    strcpy(file, optarg);
	    f_req++;
	    break;

        case 's':
            string = malloc(strlen(optarg) + 1);
	    strcpy(string, optarg);
	    s_req++;
            break;

        default: 
            fprintf(stderr, "%s", USAGE);
            return EXIT_FAILURE;
        }
    }
    
    if (argc == 1) {
        printf("%s", USAGE);
	return EXIT_FAILURE;
    }


    if (f_req == 0 || s_req == 0) {
    	fprintf(stderr, "Both -f and -s are required.\n");
	fprintf(stderr, "%s", USAGE);
	return EXIT_FAILURE; 
    }
    finf(string, file);
    
    return EXIT_SUCCESS;
}
