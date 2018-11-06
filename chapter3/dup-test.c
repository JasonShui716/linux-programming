#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int fd;
    if((fd = dup(0))!=-1)
        printf("%d\n",fd);
    if((fd = dup2(0, fd+1))!=-1)
        printf("%d\n",fd);
    else
        exit(1);
    getchar();
    exit(0);
}