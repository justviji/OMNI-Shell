//
// Created by viji on 02/05/22.
//

#include "commands.h"

void clear(){
    system("clear");
}

void wc_lc_cc(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/wc_lc_cc","/home/viji/CLionProjects/untitled21/wc_lc_cc",user_input[0], user_input[1],user_input[2],user_input[3],user_input[4],user_input[5], NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
    }
}

void ls(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/ls",user_input[0], ".", NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
    }
}

void lsr(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/lsr",user_input[0], ".", NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
    }
}

void mkdir(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/mkdir",user_input[0],user_input[1], ".", NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
    }
}

void working_dir(){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/pwd","pwd", NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
        printf("\n");
    }
}

void cd(char user_input[64]) {
    char s[100];
    fflush(stdin);
    fflush(stdout);
    getcwd(s, 100);
    chdir(user_input);

}

void echo(char user_input[maxwords][64]){
    fflush(stdin);
    fflush(stdout);
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/echo",user_input[0], user_input[1],user_input[2],user_input[3],
               user_input[4],user_input[5],user_input[6],user_input[7],user_input[8],user_input[9],user_input[10],
               user_input[11],user_input[12], user_input[13],user_input[14], NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
    }
}

void rmDir(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/rmdir",user_input[0], user_input[1], NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
    }
}

void cat(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/cat","cat", user_input[1], NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        fflush(stdout);
        wait(NULL);
    }
}

void touch(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/touch",user_input[0], user_input[1], NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
    }
}

void rm(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/rm",user_input[0], user_input[1], NULL);
    }else if(child<0){
        perror("child creation failed");
    }else{
        wait(NULL);
    }
}
