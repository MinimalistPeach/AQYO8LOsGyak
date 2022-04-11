#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    int fd, ret;
    char buf[32];
    buf[0] = 0;

    fd = open("AQYO8L.txt", O_RDWR);

    if(fd == -1)
    {
        perror("open() hiba");
        exit(-1);
    }

    ret = read(fd,buf,32);
    printf("read() beolvasott %d byteot, ami a kovetkezo %s\n",ret,buf);
    strcpy(buf,"Neptunkod");

    ret = lseek(fd,0,SEEK_SET);
    printf("lseek() : %d\n",ret);

    ret = write(fd,buf,6);
    printf("write() : %d\n",ret);

    return 0;

}
