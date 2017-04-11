#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        printf("usage: %s <pathname>", argv[0]);
        exit(-1);
    } else {

        if (access(argv[1], R_OK) < 0) {
            printf("access error for %s:%s\n", argv[1], strerror(errno));
        } else {
            printf("read access OK\n");
        }

        if (open(argv[1], O_RDONLY) < 0) {
            printf("open error for %s:%s\n", argv[1], strerror(errno));
        } else {
            printf("open for reading OK\n");
        }
        exit(0);

    }

}