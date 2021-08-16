#include <stdio.h>
#include <unistd.h>
#include "functions.h"

extern char *optarg;
extern int optind, opterr, optopt;

int main (int argc, char **argv){

    const char *opts = "f:h";
    int ret;

    while ((ret = getopt(argc, argv, opts)) != -1){
        switch (ret){
        case 'f' : ls_files(optarg); break;
        case 'h' : help(argv[0]); return 0;
        case '?' : printf("Error!"); break;
        }
    }
}