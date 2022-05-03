//
// Created by viji on 22/04/22.
//
#include "stdio.h"
int main(int counter, char * user_input[]){
    int i = 1;
    while (user_input[i][0] != '\0') {
        printf("%s ", user_input[i]);
        i++;
    }
    printf("\n");
}
