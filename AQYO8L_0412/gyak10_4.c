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
    pid_t childpid;
    char bevittsz[128];
    char readbuffer[80];
    bool kilep = false;
    int opcio;
    int db = 0;

    if((childpid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }

    char * uzenofal = "/tmp/uzenofal";

    mkfifo(uzenofal, 0666);

    if(childpid == 0)
    {
        fd = open(uzenofal, O_WRONLY);
        printf("Ide irhatja azokat a dolgokat, amiket bele szeretne irni a csovezetekbe.\nAz exit beirasaval lehet kilepni ebbol a modbol.\n");
        while(!kilep)
        {
            scanf("%s",bevittsz);
            if(strcmp(bevittsz, "exit") == 0)
            {
                kilep = true;
                close(fd);
                exit(0);
            }
            printf("Bevitt szoveg: %s\n",bevittsz);
            db = db+1;
            write(fd, bevittsz, (strlen(bevittsz)+1));

        }

    }
    else
    {
        fd = fopen(uzenofal, "r");
        if(fd == NULL)
        {
            printf("Uzenofal megnyitasa sikertelen!");
            return 0;
        }
        wait(NULL);
        printf("Valasszon feladatot:\n1 - Uzenetek darabszamanak lekerdezese\n2 - Osszes uzenet kiolvasasa\n3 - Uzenet sor megszuntetese\n4 - Kilepes");
        scanf("%d",&opcio);
        if(opcio == 1)
        {
            printf("Uzenetek darabszama: %d", db);

        }

        close(fd);
    }
    return 0;
}
