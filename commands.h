//
// Created by viji on 21/04/22.
//

#ifndef UNTITLED21_COMMANDS_H
#define UNTITLED21_COMMANDS_H
#define maxwords 16
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <errno.h>
#include <ctype.h>
#include <linux/kernel.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include "ee.h"

//colors for the shell
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

void wc_lc_cc(char user_input[maxwords][64]){
    pid_t child = fork();
    if(child==0){
        execlp("/home/viji/CLionProjects/untitled21/wc_lc_cc",user_input[0], user_input[1],user_input[2],user_input[3],user_input[4],user_input[5], NULL);
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
               user_input[11],user_input[12], NULL);
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
#endif //UNTITLED21_COMMANDS_H
#define maxwords 16

