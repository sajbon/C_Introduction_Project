#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


const int dlugosc=30;

void bar (int procenty)
{
    int liczba=procenty*dlugosc/100;
    printf("\r[");
    for(int i=0;i<liczba;i++)
    {
        printf("#");
    }
    for(int i=0;i<dlugosc-liczba;i++)
    {
        printf(" ");
    }
    printf("] %d%% Skonczone", procenty);
    fflush(stdout);
}
int main()
{
    for(int i = 0; i<= 100;i++)
    {
        bar(i);
        usleep(1000);
    }
}
