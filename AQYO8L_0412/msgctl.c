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
    char * me = "/tmp/me";

    if (remove(me) == 0) {
        printf("Letoroltem a csovezeteket!");
    } else {
        printf("Nem tudtam letorolni a csovezeteket!");
    }
    return 0;
}
