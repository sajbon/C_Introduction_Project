#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int liczba;
    srand(time(NULL));
    liczba=rand()%100;
    for(int i=0;i<10;i++)
    {
    sleep(1000);
    printf("%d\n",liczba);
    }
    return 0;
}

