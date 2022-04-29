#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void InterruptHandler(int sig);

char *AQYO8L = "/tmp/AQYO8L";
FILE *file_out;

int main()
{
    int fd;
    int count = 0;
    char readbuffer[80];
    mkfifo(AQYO8L, 0666);
    fd = open(AQYO8L, 0666);
    file_out = fopen("output.txt", "w");

    if (file_out == NULL)
    {
        printf("Hiba! Nem tudtam megnyitni a fajlt!");
        exit(-1);
    }

    if (signal(SIGINT, InterruptHandler) == SIG_ERR)
    {
        printf("Nem sikerult kezelot allitani a(z) \"SIGINT\" jelre\n");
        return 0;
    }
    printf("Elkezdtem kiolvasni a csovezetekbe irt szoveget!\n");

    while (1)
    {
        read(fd, readbuffer, sizeof(readbuffer));
        count = count + 1;
        fprintf(file_out, "%d. %s\n", count, readbuffer);

        printf("A csovezetekbe, majd fajlba irt szoveg: %s\n", readbuffer);
        sleep(1);
    }
    return 0;
}

void InterruptHandler(int sig)
{
    fclose(file_out);
    if (remove(AQYO8L) == 0)
    {
        printf("Letoroltem a csovezeteket!\n");
    }
    else
    {
        printf("Nem tudtam letorolni a csovezeteket!\n");
    }
    exit(0);
}
