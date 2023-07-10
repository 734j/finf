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
    
    while ((opt = getopt(argc, argv, "hs:f:")) != -1) {
        switch (opt) {
        case 'h':
        
            printf("%s", USAGE);
	    return EXIT_SUCCESS;
            break;
	
	case 'f':
	    file = optarg;
	    break;

        case 's':
            string = optarg;
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


    if (file == NULL || string == NULL) {
    	fprintf(stderr, "Both -f and -s are required.\n");
	fprintf(stderr, "%s", USAGE);
	return EXIT_FAILURE;
    }
    finf(string, file);


    return EXIT_SUCCESS;

}
