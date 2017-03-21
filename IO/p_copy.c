#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main(int argc, char *argv[]) 
{
    int     read_len;
    int     write_len;
    size_t  pread_offset = 0;
    size_t  pwrite_offset = 0;
    char    buf[BUFFSIZE];

    while((read_len = pread(STDIN_FILENO, buf, BUFFSIZE, pread_offset)) > 0) {

        pread_offset += read_len;

        if ((write_len = pwrite(STDOUT_FILENO, buf, read_len, pwrite_offset)) != read_len) {
            printf("write error");
            exit(-1);
        }

        pwrite_offset += write_len;

    }

    if (read_len < 0) {
        printf("read error");
        exit(-1);
    }

    exit(0);
}