//
// Created by viji on 02/05/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int counter, char * user_input[]) {

    char ch;
    int char_count = 0, word_count = 0, line_count = 0;
    int in_word = 0;
    FILE *fp;

    fp = fopen(user_input[1], "r");

    if(fp == NULL) {
        printf("Could not find or open the file %s\n", user_input[1]);
        fclose(fp);
    }

    while ((ch = fgetc(fp)) != EOF) {
        char_count++;

        if(ch == ' ' || ch == '\t' || ch == '\0' || ch == '\n') {
            if (in_word) {
                in_word = 0;
                word_count++;
            }

            if((ch = '\0' || ch == '\n')) line_count++;

        } else {
            in_word = 1;
        }
    }
    if(strcmp(user_input[0],"cc")==0)
    printf("Number of characters: %d.\n", char_count);
    else if(strcmp(user_input[0],"wc")==0)
    printf("Number of words: %d.\n", word_count);
    else
    printf("Number of lines: %d.\n", line_count+1 );
    fclose(fp);

    return EXIT_SUCCESS;
}