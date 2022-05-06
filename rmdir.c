//
// Created by viji on 02/05/22.
//
#include <dirent.h>                         ///for directories
#include <stdio.h>
#include <string.h>

#define WHITE  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"        ///note: different colors then in the main file




void ls(char * path){
    DIR * d = opendir(path);

    if(d==NULL) return;
    struct dirent * dir;
    while ((dir = readdir(d)) != NULL){

        if(dir-> d_type != DT_DIR) {
            remove(dir->d_name);
        }
            //remove(dir);
        else
        if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ){ // if it is a directory
            ls(dir->d_name);
            remove(dir->d_name);
        }
    }
    closedir(d);
}

int main(int argc, char *user_input[])
{
    printf("%s\n", WHITE);
    ls(user_input[1]);
    printf("%s\n", WHITE);
    return 0;
}