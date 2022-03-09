#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char par[25];

    do
    {
        printf("Kerek egy parancsot: ");
        scanf("%s", &par);
        system(par);

    }
    while(true);
    return 0;
}
