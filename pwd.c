//
// Created by viji on 29/04/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 200
int main(void) {
    char path[MAX];
    if (getcwd(path, MAX) == NULL) {
        perror("Eror getting the path\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", path);

    exit(EXIT_SUCCESS);
}