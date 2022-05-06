#include "commands.h"


long get_uptime(){
    struct sysinfo s_info;
    int error = sysinfo(&s_info);
    if(error != 0)
    {
        printf("code error = %d\n", error);
    }
    return s_info.uptime;
}
void initPrint(){               //printing the name and the symbol of the shell on startup
    struct utsname name;        //for the info of the system on startup
    if(uname(&name)) exit(EXIT_FAILURE);
    int i = 0;
    char hostname[32];
    char username[32];
    long ver[16];
    gethostname(hostname,32);
    getlogin_r(username, 32);
    char * p = name.release;

    while (*p) {
        if (isdigit(*p)) {
            ver[i] = strtol(p, &p, 10);
            i++;
        } else {
            p++;
        }
    }


    printf("\n\n"BRED
           "               .ooooooo.           "BWHT"       shell:"WHT"OMNI-SHELL\n"BRED                        //idea from internet but selfmade ascii art
           "           .d8888888888888b.     "BWHT"         OS:"WHT"%s \n"BRED
           "         d88P\"          \"Y88b    "BWHT"         host:"WHT"%s\n"BRED
           "        8888              8888     "BWHT"       Kernel version"WHT":%ld.%ld.%ld.%ld\n "BRED
           "       8888              8888       "BWHT"     Uptime:"WHT"%ld min\n"BRED
           "         888              888\n"
           "         Y88b            d88P \n"
           "          \"88bo         od88\" \n"
           "        d888888        8888888b\n\n"WHT,name.sysname,hostname,ver[0],ver[1],ver[2],ver[3]/*Kernel 0 Major 1 Minor 2 Patch 3*/, get_uptime()/60);
}
void newCommandPrint(){
    getc(stdout);
    char hostname[32];
    char username[32];
    gethostname(hostname,32);
    getlogin_r(username, 32);
    printf(BLU" %s",username);
    printf(WHT"@");
    printf(BBLU"%s",hostname);
    printf(WHT" in "MAG);
    fflush(stdout);
    working_dir();
    printf(WHT" \u03A9  "WHT);

}
void getString(char user_input[maxwords][64]){
    getc(stdout);
    char buffer[64];
    fflush(stdin);
    for (int i = 0; i < maxwords; ++i) {
        for (int j = 0; j < 64; ++j) {
            user_input[i][j] = '\0';
        }
    }
    scanf("%[^\n]s",buffer);
    getc(stdin);
    int k = 0;
    int j = 0;
    int l = 0;
    while (true) {
        if(buffer[l]=='\0')break;
        if(buffer[l] == ' '){
            k++;
            j=0;
            l++;
        } else{
            user_input[k][j]=buffer[l];
            j++;
            l++;
        }
    }
}

int main() {
    //FILE * last_command = NULL;
    //last_command = fopen("history.txt", "a");
    clear();
    initPrint();
    bool exit_flag = false;
    char user_input[maxwords][64] = {};
    cd("/home");
    while(exit_flag == false){

        newCommandPrint();
        getString(user_input);


        if(strcmp(user_input[0],"echo")==0){
            echo(user_input);
        }else if(strcmp(user_input[0],"exit")==0 || strcmp(user_input[0],"q")==0){
            exit_flag = true;
        }else if(strcmp(user_input[0],"cd")==0){                ///change direcory
            chdir(user_input[1]);
        }else if(strcmp(user_input[0],"pwd")==0){
            working_dir();
        }else if(strcmp(user_input[0],"cd")==0){
            cd(user_input[1]);
        }else if(strcmp(user_input[0],"cc")==0||strcmp(user_input[0],"wc")==0||strcmp(user_input[0],"lc") == 0){
            wc_lc_cc(user_input);
        }else if(strcmp(user_input[0],"cat")==0){
            cat(user_input);
        }else if(strcmp(user_input[0],"ls")==0){
            ls(user_input);
        }else if(strcmp(user_input[0],"rmdir")==0){
            rmDir(user_input);
        }else if(strcmp(user_input[0],"mkdir")==0){
            mkdir(user_input);
        } else if(strcmp(user_input[0],"touch")==0){
            touch(user_input);
        }else if(strcmp(user_input[0],"clear")==0) {
            clear();
        }else if(strcmp(user_input[0],"rm")==0){
                rm(user_input);
        }else{
            printf(BRED"Error: "WHT"command not found\n");
            fflush(stdout);
            fflush(stdin);
            }
        //fprintf(last_command,"%s %s %s",user_input[0],user_input[1],user_input[2]);
        }
    //fclose(last_command);
    return EXIT_SUCCESS;
}