#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void) 
{
    umask(0);

    if (creat("foo", RWRWRW) < 0) {

        printf("create error for foo:%s\n", strerror(errno));

    }

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0) {

        printf("create error for bar:%s\n", strerror(errno));

    }

    exit(0);
}