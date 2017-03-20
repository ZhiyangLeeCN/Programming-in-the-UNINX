#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void) {

    int fd;

    if ((fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {

        printf("create error!");
        exit(-1);

    }

    if (write(fd, buf1, 10) != 10) {

        printf("buf1 write error");
        exit(-1);

    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {

        printf("buf lseek error");
        exit(-1);

    }

    if (write(fd, buf2, 10) != 10) {

        printf("buf2 write error");
        exit(-1);

    }

    exit(0);


}