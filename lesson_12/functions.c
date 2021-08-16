#include "functions.h"

int ls_files(const char *path)
{
    //printf ("all ok!");
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char full_name[255] = { 0 };
    
    dir = opendir(path);
    
    if (dir) {
        printf ("\tls from %s directory\n", path);
        while (entry = readdir(dir)) {
            if (entry->d_name[0] == '.')    continue;

            memset(full_name, 0, 255);
            sprintf(full_name, "%s/%s", path, entry->d_name);
            full_name[254] = '\0';

            if (stat(full_name, &file_info) == 0)
                {
                if (S_ISDIR(file_info.st_mode) == 1) 
                    {
                    printf ("->%s (DIR)\n",full_name);
                    ls_files(full_name);
                } 
                else printf ("%s\n",full_name);
            }
        }printf("\n\n");
    }
    return 0;
}

void help(const char *appname){
    printf("\tThis programm is for tree-type content printing\n");
    printf("\tuse: %s [path]\n", appname);
}