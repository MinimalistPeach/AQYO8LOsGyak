#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char temp[100];

    if ((fp = fopen("vezeteknev.txt","r")) == NULL){
       printf("Nincs ilyen fajl, igy letrehoztam!\n");
       fp = fopen("vezeteknev.txt", "w");
       fprintf(fp, "Stremler Laszlo, AQYO8L, Programtervezo Informatikus");
       printf("Stremler Laszlo, AQYO8L, Programtervezo Informatikus\n");
    }
    else {
        fgets(temp, 100, fp);
       printf("%s\n", temp);
    }

    fclose(fp);
    system("PAUSE");
    return(0);
}
