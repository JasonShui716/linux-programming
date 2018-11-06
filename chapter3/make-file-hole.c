#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void){
    int fd;
    if((fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0){
        fprintf(stderr, "creat error");
    }
    
    if(write(fd, buf1, 10) != 10)
        fprintf(stderr, "buf1 write error");

    if(lseek(fd, 16384, SEEK_SET) == -1)
        fprintf(stderr, "lseek error");

    if(write(fd, buf2, 10) != 10)
        fprintf(stderr, "buf2 write error");

    exit(0);
}