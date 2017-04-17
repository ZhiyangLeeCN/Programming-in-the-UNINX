#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(void) 
{
    if (open("tempfile", O_RDWR) < 0) {
        printf("open error:%s\n", strerror(errno));
        exit(errno);
    }

    if (unlink("tempfile") < 0) {
        printf("unlink error:%s\n", strerror(errno));
        exit(errno);
    }

    sleep(15);

    printf("done\n");
    exit(0);
}