//
// Created by viji on 29/04/22.
//

#include <stdio.h>

int main(int counter, char * user_input[]){
    FILE * file = NULL;
    char c;
    file = fopen(user_input[1],"r");
    if(file != NULL) {
        while (1) {
            c = fgetc(file);
            if (feof(file)) {
                break;
            }
            printf("%c", c);

        }

        fclose(file);
        printf("\n");
        return 0;
    } else{
        fclose(file);
        perror("\e[1;31m" "the file is not found");

    }
}