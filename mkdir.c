//
// Created by viji on 02/05/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


int main(int stuff, char ** userin) {
    if(mkdir(userin[1], S_IRWXU)==0){        ///S_IRWXU for read write and execute
        exit(EXIT_SUCCESS);
    }else{
        perror("directory could not be created\n");
        exit(EXIT_FAILURE);
    }

}