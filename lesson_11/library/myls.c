#include "myls.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void ls_files(const char *path)
{
    //printf ("all ok!");
    DIR *dir;
    struct dirent *entry;
    
    dir = opendir(path);
    printf ("ls from %s directory\n", path);
    if (dir) {
        while (entry = readdir(dir)) {
            if (entry->d_name[0] == '.') {
                continue;
            }
            printf ("file %s\n", entry->d_name);
        }
    }
    
}
