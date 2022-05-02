#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 6666
#define PERM 00666

int main( ) {
    int p1=fork();
    int id;
    struct sembuf up[1]  =  {0,  1, SEM_UNDO};
    struct sembuf down[1] = {0, -1, SEM_UNDO};
    if(p1 == 0)
    {

         if ((id = semget(KEY, 1, 0)) < 0) { 
        if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0) {
            perror(" A szemafor nem nyithato meg. ");
            exit(-1);
            }
        }
        else{
            perror(" Mar letezik a szemafor. ");
            exit(0);
        }

        if (semctl(id, 1, SETVAL, 1) < 0) {
             perror(" Nem lehetett inicializalni. ");
        } 
        else {
            puts(" Kész is inicializalt a szemafor. ");
        }
    }
    else
    {
        int c=0;
        while(c<3)
        {
            semop(id, down, 1);   
            sleep(3);
	        puts("Itt fut a kritikus szakasz.");	
	        semop(id, up, 1);   
            c++;
        }
    }
    int p2=fork();
    if(p2 == 0)
    {
        if ((id = semget(KEY, 1, 0)) < 0) { 
		perror(" Mar nem letezik a szemafor. ");
		exit(-1);
	    }
    }
}