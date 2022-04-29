#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

int main()
{
    int fd;
    bool kilep = false;
    char bevittsz[128];

    char *me = "/tmp/AQYO8L";

    fd = open(me, O_WRONLY);
    wait(NULL);
    printf("Ide irhatja azokat a dolgokat, amiket bele szeretne irni a csovezetekbe.\nAz exit beirasaval lehet kilepni ebbol a modbol.\n");
    while (!kilep)
    {
        scanf("%s", bevittsz);
        if (strcmp(bevittsz, "exit") == 0)
        {
            kilep = true;
            close(fd);
            exit(0);
        }
        else
        {
            printf("Bevitt szoveg: %s\n", bevittsz);
            write(fd, bevittsz, (strlen(bevittsz) + 1));
        }
    }
    return 0;
}
