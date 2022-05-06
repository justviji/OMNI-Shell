//
// Created by viji on 29/04/22.
//
#include<unistd.h>
#include <stdio.h>
int main(int counter, char * user_input[])
{
    char s[100];
    getcwd(s, 100);
    if(!chdir(user_input[1])){
        printf("\e[1;31m chdir() to %s failed\n", user_input[1]);
        return -1;
    }
    getcwd(s, 100);
    return 0;
}