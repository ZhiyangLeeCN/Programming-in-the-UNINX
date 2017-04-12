#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    struct stat statbuf;

    if (stat("foo", &statbuf) < 0) {
        printf("stat error for foo:%s\n", strerror(errno));
    }

    if (chmod("foo", (statbuf.st_mod & ~S_IXGRP) | S_ISGID) < 0) {
        printf("chmod error for foo:%s\n", strerror(errno));
    }

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
        printf("chmod error for bar:%s\n", strerror(errno));
    }

    exit(0);

}
