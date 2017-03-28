#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf2[] = "_test_";

    if (argc != 2) 
    {
        printf("usage: file_name\n");
        exit(-1);
    } else {
        int fd = open(argv[1], O_RDWR | O_APPEND);
        printf("open file:%s\n", argv[1]);
        if (fd > 0) {

            printf("fd:%d\n", fd);

            off_t currpos = lseek(fd, 2, SEEK_SET);

            write(fd, buf2, 6);

            printf("write success\n");

        } else {

            printf("file not found\n");
            exit(-1);

        }

    }

}