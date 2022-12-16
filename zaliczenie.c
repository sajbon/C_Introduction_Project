#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

const int dlugosc=30;

int zawodnicy()
{
    FILE *dane;                                                 //Otwieram plik txt z zawonikami.
   if((dane = fopen("Zawodnicy.txt","r")) == NULL)              //Tworze warunek, ktory jezeli nie zostanie spelniony to program wypluje nam informacje ze nie mozemy otworzyc pliku.
   {
       printf("Nie mozna otworzyc pliku");
       exit(1);
   }
   char lista[100];
   char* token;
   fgets(lista,100,dane);                                      //Wczytuje plik txt z zawodnikami.
   token=strtok(lista," ");

   while(token!=NULL)                                           //Wczytuje plik txt z zawodnikami do momentu wypisania ostatniego zawodnika.
   {
       printf(" %s\n",token);
       token = strtok(NULL," ");
   }
   fclose(dane);                                                 //ZAamykam plik.
   int flaga=0;
   int szansa=0;
   int tab[4];
    for(int i=0;i<5;i++)                                        //Tworze petle, która w razie bledu ponawia sie do momentu wybrania 5 roznych zawodnikow.
    {
        scanf("%d",&tab[i]);
        for(int j=0;j<=i;j++)
        {
            if(tab[i]==tab[j-1])
            {
                printf("Wybrales juz tego zawodnika. Wybierz ponownie.\n");
                i=i-1;
                flaga=1;
            }
        }
        if(flaga==0)
        {
            if(tab[i]==1)
            {
                printf("Wybrales s1mple\n");
                szansa=szansa+5;
            }
            if(tab[i]==2)
            {
                printf("Wybrales Zyw0o\n");
                szansa=szansa+5;
            }
            if(tab[i]==3)
            {
                printf("Wybrales nsh1ro\n");
                szansa=szansa+3;
            }
            if(tab[i]==4)
            {
                printf("Wybrales mir\n");
                szansa=szansa+4;
            }
            if(tab[i]==5)
            {
                printf("Wybrales olofmeister\n");
                szansa=szansa+5;
            }
            if(tab[i]==6)
            {
                printf("Wybrales NiKo\n");
                szansa=szansa+5;
            }
            if(tab[i]==7)
            {
                printf("Wybrales coldzera\n");
                szansa=szansa+4;
            }
            if(tab[i]==8)
            {
                printf("Wybrales dev1ce\n");
                szansa=szansa+4;
            }
            if(tab[i]==9)
            {
                printf("Wybrales GeT_RiGhT\n");
                szansa=szansa+3;
            }
            if(tab[i]==10)
            {
                printf("Wybrales PaszaBiceps\n");
                szansa=szansa+5;
            }
        }
        flaga=0;
    }
    return(szansa);
   }



int strona()                                                        //Jest to funkcja polegajaca na wyborze strony przez uzytkownika T lub AT.
{
    int wybor;
    printf("\n\t\t   Wybierz jedna ze stron:\n\n\tTerrorysci:1\t\t\tAntyterrorysci:2\n");
    scanf("%d",&wybor);
    if(wybor==1)
        printf("\t\tWybrales strone: Terrorystow (T)\n");
    else if(wybor==2)
        printf("\t\tWybrales strone: Antyterrorystow (CT)\n");
    else
        printf("Wpisales niepoprawna liczbe\n");
    return(wybor);                                                      //Zwraca która druzyne wybral uzytkownik.
}

void loadingbar (int procenty)                                             //Funkcja polegajaca na wyswietleniu ladujacego sie paska od 0 do 100% co kazda runde.
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
    printf("] %d%% Skonczone ", procenty);
    fflush(stdout);                                                //Komenda czyszczaca konsole.
}

int losowosc()                                                      //Jest to funkcja odpowiadająca za losowanie liczby.
{
    int los;
    srand(time(NULL));                                              //Uzylem funkcji srand zeby liczba byla za kazdym razem losowa.
    los=rand()%100;                                                 //Gdyby nie funkcja srand to rand wyrzucalby za kazdym odpaleniem konsoli ten sam ciag liczb.
    return (los);
}

int rundy()
{
    int szansa=zawodnicy();     //
    int wybor=strona();         //Tworze zmienne z wartosci ktore zwracaja funkcje.
    int budzet=800;             //
    int ekwipunek=0;            //
    int zestaw;                 //Deklaruje potrzebne zmienne.
    printf("\t\tTwoj budzet wynosi: 800$\n\n");
    Sleep(1000);
    printf("Co chcesz zeby twoi zawodnicy kupili?\n\n\tBazowo twoja druzyna wyposazona jest w pistolety Glock-18\n\n");
    Sleep(3000);
    printf("Czy chcesz zeby twoja druzyna kupila Kevlar: 650$? \nUWAGA: Jezeli kupisz kevlar nie bedzie cie stac na nic innego.\n\n\t\tTak:1\t\t\tNie:2\n\n");
    int kevlar;
    scanf("%d",&kevlar);

    if(kevlar==1)               //Funkcja mowiaca czy uzytkownik kupil kevlar w 1 rundzie.
    {
        budzet=budzet-650;
        printf("\nKupiles Kevlar, twoj budzet wynosi:%d\n\n",budzet);
        ekwipunek=szansa+20;
    }
    else                        //Jezeli nie, to ma mozliwosc kupna broni, gdyz budzet w 1 rundzie wynosi 800$. Dlatego uzytkownik musi wybrac miedzy pancerzem a bronia.
    {
        printf("\nNie Kupiles Kevlaru, twoj budzet wynosi:%d\n\nLista dostepnych przedmiotow:\n\n",budzet);
        Sleep(2000);
        printf("\t1. Dual Berettas: 400$  \n\t2. P250: 300$ \n\t3. Tec-9: 500$ \n\t4. Desert Eagle: 700$ \n");
        scanf("%d",&zestaw);
        if(zestaw==1)
        {
            budzet=budzet-400;
            printf("Zakupiles Dual Beretty, Twoj budzet wynosi %d",budzet);
            ekwipunek=szansa+6;
        }
        else if(zestaw==2)
        {
            budzet=budzet-300;
            printf("Zakupiles P250, Twoj budzet wynosi %d",budzet);
            ekwipunek=szansa+4;
        }
        else if(zestaw==3)
        {
            budzet=budzet-500;
            printf("Zakupiles Tec-9, Twoj budzet wynosi %d",budzet);
            ekwipunek=szansa+7;
        }
        else if(zestaw==4)
        {
            budzet=budzet-700;
            printf("Zakupiles Desert Eagle, Twoj budzet wynosi %d",budzet);
            ekwipunek=szansa+10;
        }
    }
    int win=0;                  //
    int loss=0;                 //Zmienne sumujace wygrane i przegrane rundy.
    for(int b=1;b<=30;b++)
    {
        printf("\n\t\t Zaczyna sie %d runda",b);        //
        printf("\n\t\t Zaczyna sie %d runda",b);        //Problem z ktorym bylem na konsultacjach, przez wewnetrzna petle jest pomijana 1 instrukcja.
        for(int i=0;i<=100;i++)                         //Petla odpowiadajaca za pasek ladowania sie.
        {
            loadingbar(i);
            usleep(2000);
        }
        int a=losowosc();                               //Deklaruje zmienna i nadaje jej wartosc zwrocona przez funkcje.
        if(ekwipunek>=a)                                //Warunek odpowiada za porownanie liczby punktow zebranych przez uzytkownika(zawodnicy,bronie,pancerz-kazda z tych rzeczy a okreslona liczbe punktow) z losowa liczba. W zaleznosci ktora z nich jest wieksza uzytkownik wygrywa badz przegrywa.
        {
            budzet=budzet+3250;                         //Rozny przychod w zaleznosci od wygrania badz przegrania rundy.
            printf("\n\t\tWygrywasz %d runde.\n\n\t\t Twoj budzet wynosi: %d$\n", b, budzet);
            win=win+1;
            if(win==16)
            {
                printf("\n\n\t\tWygrales gre. gratulacje.\n\n");
                return(0);
            }
        }
        else                                            //Rozny przychod w zaleznosci od wygrania badz przegrania rundy.
        {
            budzet=budzet+1900;
            printf("\n\t\tPrzegrywasz %d runde.\n\n\t\t Twoj budzet wynosi: %d$\n", b, budzet);
            loss=loss+1;
            if(loss==16)
            {
                printf("\n\n\t\tPrzegrales gre. :c\n\n");
                return(0);
            }
        }
        if(win==15&&loss==15)                           //Okropny sposob na sprawdzenie czy mecz nie zakonczy sie remisem. Niestety nie bylem w stanie wpasc na lepszy pomysl.
        {
            printf("Mecz zakonczony remisem.");
            return(0);
        }
        printf("Bierzacy wynik: Twoje rundy: %d Rundy komputera: %d\n",win,loss);       //Instrukcja wypisujaca bierzacy wynik.
        ekwipunek=0;
        ekwipunek=szansa;                               //Jako ze ekwipunek zmienia sie w zaleznosci od rundy, a wartosc punktow zebranych za pomoca zawodnikow nie, to po kazdej rundzie punkty za bronie sa zerowane.
        Sleep(1000);
        printf("Co chcesz zeby twoi zawodnicy kupili?\n\nLista dostepnych przedmiotow:\n\n");
        Sleep(3000);
        printf("\t\t 1. Kevlar: 650$\n\t\t 2. Kevlar+Helm 1000$\n\t\t 3. Nie kupuje zadnego pancerza\n");
        int kevlar;
        scanf("%d",&kevlar);
        if(kevlar==1)                                   //Warunek kupna pancerza w nastepnych rundach.
        {
            budzet=budzet-650;
            printf("\nKupiles Kevlar, twoj budzet wynosi:%d$\n\n",budzet);
            ekwipunek=ekwipunek+5;
        }
        else if(kevlar==2)
        {
            budzet=budzet-1000;
            printf("\nKupiles Kevlar+Helm, twoj budzet wynosi:%d$\n\n",budzet);
            ekwipunek=ekwipunek+8;
        }
        else if(kevlar==3)
        {
            printf("\n Nie kupiles Kevlaru, twoj budzet wynosi:%d$\n\n",budzet);
        }
        Sleep(2000);
        powrot:                         //Uzylem funkcji goto gdyz wydala mi sie najprostsza, zostala zastosowana zeby program nie pozwolil uzytkownikowi kupic broni na ktora go nie stac.
        printf("UWAGA: Jezeli niemasz wystarczajacej ilosci pieniedzy wybierz opcje nr 6.\n\n\t1. Galil AR: 1800$ (T)\n\t1.FAMAS: 2050$ (AT)\n\t2. Ak47: 2700$ (T)\n\t2. M4A1-S 2900$ (AT) \n\t3. SSG 08: 1700$\n\t4. SG 553: 3000$ (T)\n\t4.AUG: 3300$ (AT) \n\t5. AWP: 4750$\n\t6.Nic\n");
        scanf("%d",&zestaw);
        if(zestaw==1)
        {
            if(wybor==1)
            {
                if(budzet>=1800)        //Warunek przez ktory nie mozemy kupic broni na ktora nas nie stac.
                {
                    budzet=budzet-1800;
                    printf("Zakupiles Galil AR, Twoj budzet wynosi %d$",budzet);
                    ekwipunek=ekwipunek+10;
                }
                else
                {
                    printf("\nNie masz wystarczajacej ilosci srodkow.\n");
                    goto powrot;
                }
            }
            else if(wybor==2)
            {
                if(budzet>=2050)        //Warunek przez ktory nie mozemy kupic broni na ktora nas nie stac.
                {
                    budzet=budzet-2050;
                    printf("Zakupiles FAMAS, Twoj budzet wynosi %d$",budzet);
                    ekwipunek=ekwipunek+12;
                }
                else
                {
                    printf("\nNie masz wystarczajacej ilosci srodkow.\n");
                    goto powrot;
                }
            }
        }
        if(zestaw==2)
        {
            if(wybor==1)
            {
                if(budzet>=2700)        //Warunek przez ktory nie mozemy kupic broni na ktora nas nie stac.
                {
                    budzet=budzet-2700;
                    printf("Zakupiles Ak47, Twoj budzet wynosi %d$",budzet);
                    ekwipunek=ekwipunek+16;
                }
                else
                {
                    printf("\nNie masz wystarczajacej ilosci srodkow.\n");
                    goto powrot;
                }
            }
            else
            {
                if(budzet>=2900)           //Warunek przez ktory nie mozemy kupic broni na ktora nas nie stac.
                {
                    budzet=budzet-2900;
                    printf("Zakupiles M4A1-S, Twoj budzet wynosi %d$",budzet);
                    ekwipunek=ekwipunek+17;
                }
                else
                {
                    printf("\nNie masz wystarczajacej ilosci srodkow.\n");
                    goto powrot;
                }
            }
        }
        if(zestaw==3)
        {
            if(budzet>=1700)                //Warunek przez ktory nie mozemy kupic broni na ktora nas nie stac.
            {
                budzet=budzet-1700;
                printf("Zakupiles SSG 08, Twoj budzet wynosi %d$",budzet);
            }
            else
            {
                printf("\nNie masz wystarczajacej ilosci srodkow.\n");
                goto powrot;
            }
        }
        if(zestaw==4)
        {
            if(wybor==1)
            {
                if(budzet>=3000)            //Warunek przez ktory nie mozemy kupic broni na ktora nas nie stac.
                {
                    budzet=budzet-3000;
                    printf("Zakupiles SG 553, Twoj budzet wynosi %d$",budzet);
                    ekwipunek=ekwipunek+15;
                }
                else
                {
                    printf("\nNie masz wystarczajacej ilosci srodkow.\n");
                    goto powrot;
                }
            }
            else
            {
                if(budzet>=3300)            //Warunek przez ktory nie mozemy kupic broni na ktora nas nie stac.
                {
                    budzet=budzet-3300;
                    printf("Zakupiles AUG, Twoj budzet wynosi %d$",budzet);
                    ekwipunek=ekwipunek+16;
                }
                else
                {
                    printf("\nNie masz wystarczajacej ilosci srodkow.\n");
                    goto powrot;
                }
            }
        }
        if(zestaw==5)
        {
            if(budzet>=4750)                //Warunek przez ktory nie mozemy kupic broni na ktora nas nie stac.
            {
                budzet=budzet-4750;
                printf("Zakupiles AWP, Twoj budzet wynosi %d$",budzet);
            }
            else
            {
                printf("\nNie masz wystarczajacej ilosci srodkow.\n");
                goto powrot;
            }
        }
        if(zestaw==6)
            printf("Nie kupiles nic, Twoj budzet wynosi %d$\n",budzet);
    }
    return 0;
}

int main()
{
   printf("\nWitaj w grze CS:GO Manager.");
   Sleep(1000);
   printf("\n\nRozgrywka rozpoczyna sie\n");
   Sleep(3000);
   printf("\n\nAby rozpoczac gre wybierz 5 zawodnikow: \n\n");
   rundy();
   return 0;
}
