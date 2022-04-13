#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int fd;
    char readbuffer[80];
    char * me = "/tmp/me";

    fd = open(me, O_RDONLY);
    printf("Elkezdem kiolvasni a csovezetekbe irt szoveget!\n");
    read(fd, readbuffer, sizeof(readbuffer));
    printf("Sikerult kiolvasnom a csovezetekbol a szoveget!\n");
    printf("%s", readbuffer);
    close(fd);
    return 0;
}
