
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *file;
    struct stat mystat;

    char buf[512];
    mydir = opendir(argv[1]);
    while((file = readdir(mydir)) != NULL)
    {
        sprintf(buf, "%s/%s", argv[1], file->d_name);
        stat(buf, &mystat);
        printf("%zu",mystat.st_size);
        printf(" %s\n", file->d_name);
    }
    closedir(mydir);
}