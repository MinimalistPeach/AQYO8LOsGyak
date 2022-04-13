#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd;
    char readbuffer[80];
    char string[] = "Stremler Laszlo\nAQYO8L";

    char * me = "/tmp/me";

    mkfifo(me, 0666);
    fd = open(me, O_WRONLY);
    wait(NULL);
    printf("Elkezdtem irni a csovezetekbe!!\n");
    write(fd, string, (strlen(string)+1));
    printf("Csovezetekbe iras sikeres!\n");
    close(fd);

    return 0;
}
