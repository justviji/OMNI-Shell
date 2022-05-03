//
// Created by viji on 02/05/22.
//
#include <stdio.h>

int main(int argv, char ** argc){
    FILE * fp = NULL;
    fp = fopen(argc[1],"w");
    fclose(fp);
}