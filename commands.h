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

//executes system("clear")
void clear();
/*wc lc cc
  wc counts how many words are in a document or file
  lc counts how many lines are in a document or file
  cc counts how many characters are in a doc of file*/
void wc_lc_cc(char user_input[maxwords][64]);
//ls prints all documents or folders in the current directory
void ls(char user_input[maxwords][64]);
//lsal doesnt work
void lsr(char user_input[maxwords][64]);
// creates a new directory with the name given
void mkdir(char user_input[maxwords][64]);
// prints the current working directory
void working_dir();
// changes the directory to the input
void cd(char user_input[64]);
// prints the string after the command
void echo(char user_input[maxwords][64]);
// prints the contents of a file
void cat(char user_input[maxwords][64]);
// creates a file with the name given by user
void touch(char user_input[maxwords][64]);
// removes the file  with the given name
void rm(char user_input[maxwords][64]);


#endif //UNTITLED21_COMMANDS_H
#define maxwords 16

