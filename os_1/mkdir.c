#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char**argv){
    int ret = 0;
    ret = mkdir(argv[0], 0755);
    if (ret == 0)
        printf("Directory created successfully %s\n ",argv[0]);
    else
        printf("Unable to create directory %s\n", argv[0]);
    return 0;
}
