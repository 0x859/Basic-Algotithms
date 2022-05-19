/* Aleksander Sozański,
         226638,
       semestr 3,
rok akademicki 2020/2021 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

void gotoxy (int x, int y);
void menu();
void wypiszTablice();
void placeHolder();
void wizytowka();
void trescZadania1();
void trescZadania2();
void ornament();
void stop_przycisk(void funkcja());

void printBinary(int n, int i)
{
    // Wypisuje binarna reprezentacje
    // liczby n do i bitow
    for (int k = i - 1; k >= 0; k--) {

        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}
typedef union {

    float f;
    struct
    {
        // Kolejnosc ma znaczenie
        // Czlonkowie unii korzystaja
        // z tej samej pamieci (32 bity).
        // Kolejnosc brana jest
        // od LSB do MSB.
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;

    } raw;
} myfloat;

/* Funkcja konwersji liczby rzeczywistej do standardu IEEE 754 */
void printIEEE(myfloat var)
{
    /* Wypisuje reprezentacje IEEE zminnej float (32bity) */
    printf("%d   ", var.raw.sign, 1);
    printBinary(var.raw.exponent, 8);
    printf("   ");
    printBinary(var.raw.mantissa, 23);
    printf("\n");
}
int main()
{
    system("cls");
    system("title Metody Numeryczne");
    wizytowka();
    Sleep(1000);
    menu();
    return 0;
}
void zadanie1()
{
    trescZadania1();
    ornament();

    unsigned int ccTab[32];
    unsigned int cuTab[32];
    unsigned int cwTab[32];
    myfloat var;
    float a;

    printf("\n\tWprowadz liczbe rzeczywista do konwersji: ");
    scanf("%f", &a);
    while(a == 0)
    {
        printf("\tPodana liczba musi byc rozna od. 0 :)");
        printf("\n\tWprowadz liczbe rzeczywista do konwersji: ");
        scanf("%f", &a);
    }

    var.f = a;
    int cc = (int) a;
    float cu = a - cc;
    float frem = cu*2;
    int ileft = cc;
    printf("\tCzesc calkowita liczby:%d                 Czesc ulamkowa kiczby:%f", cc, cu);
    for ( int i = 0; i < 32; i++ )
    {
        int irem;
        irem = ileft % 2;
        printf("\n\tKrok %d: %d*1/2, Wynik = %d, Reszta = %d", i+1, ileft, irem, ileft / 2);
        ccTab[i] = irem;
        ileft /= 2;
    }

    for (int i = 0; i < 32; i++)
    {
        if (frem < 1)
        {
            cuTab[i] = 0;
        }
        if (frem >= 1)
        {
            cuTab[i] = 1;
            frem -= 1;
        }
        gotoxy(58,9+i);
        printf("Krok %d: %0.4f*2, Wynik = %d, Reszta = %0.4f", i+1, frem/2, cuTab[i], 2*frem);
        frem *= 2;
    }
    printf("\n\n\tReprezentacja binarna czesci ulamkowej: ");
    int licznik1 = 0, flag1 = 0;
    for (int i = 31; i >=0 ; i--)
    {
        if (cuTab[i] == 0 && flag1 == 0)
        {
            licznik1++;
        }
        if (cuTab[i] == 1)
        {
            flag1 = 1;
        }
    }
    for (int i = 0; i < 33 - licznik1; i++)
    {
        printf("%d", cuTab[i]);
    }
    printf("\n\tReprezentacja binarna czesci calkowitej: ");
    int licznik = 0, flag = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (ccTab[i] == 0 && flag == 0)
        {
            licznik++;
        }
        if (ccTab[i] == 1)
        {
            flag = 1;
        }
    }
    for (int i = 31 - licznik; i >= 0; i--)
    {
        printf("%d", ccTab[i]);
    }
    printf("\n\tLiczba rzeczywista w ukladzie pozycyjnym o podstawie 2:\n\t");
     for (int i = 31; i >= 0; i--)
    {
        if (ccTab[i] == 0 && flag == 0)
        {
            licznik++;
        }
        if (ccTab[i] == 1)
        {
            flag = 1;
        }
    }
    for (int i = 31 - licznik; i >= 0; i--)
    {
        printf("%d", ccTab[i]);
    }
    printf(".");
    for (int i = 0; i < 33 - licznik1; i++)
    {
        printf("%d", cuTab[i]);
    }

    printf("\n\tLiczba rzeczywista w ukladzie pozycyjnym o podstawie 10:\n\t%0.8f = %12.5e",a, a);
    printf("\n\tReprezentacja liczby %f, w standardzie IEEE: \n\t",
    var.f);
    printIEEE(var);
    ornament();
    stop_przycisk(zadanie1);
    menu();
}
void zadanie2()
{
    trescZadania2();
    ornament();
    double epsilon = 1.0;
    double x;
    printf("Podaj liczbe rzeczywsta: ");
    scanf("%lf", &x);
    printf( "epsilon;  %f + epsilon\n", x);

    do
     {
       printf( "%G\t%.20f\n", epsilon, (x + epsilon) );
       epsilon /= 2.0f;
     }
    while ((x + (epsilon/2.0)) != x);

    printf( "\nWyliczony epsilon maszynowy: %G\n", epsilon );
    ornament();
    stop_przycisk(zadanie2);
    menu();
}

/////////////////////////////////////////////////////////////////
/* Ponizej znajduja sie funkcje, tzw. "upiekszacze",
ktore nadaja programowi ladny i przejrzysty wyglad. */
/////////////////////////////////////////////////////////////////

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/* Cialo funkcji gotoxy, ktorej uzywamy do rysowania */
void gotoxy (int x, int y)
{
    COORD coord = { 0 ,0 };
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void wypiszTablice(int x, int y, int czas, int dT ,char tab[30], int c)
{
    color(c);
    gotoxy(x,y);
    for(int i=0;i<dT;i++)
    {
        Sleep(czas);
        printf("%c", tab[i]);
    }
}
void wizytowka()
{
    for(int c=1, i=0, j=39, k=76; i<18; i++){
        color(c);
        gotoxy(++j,7);printf("*");
        gotoxy(--k,7);printf("*");
        Sleep(10);
        c++;
        if (c == 7){
            c=1;
        }
    }
        for(int c=1, i=8; i<=15; i++){
        color(c);
        gotoxy(40,i);printf("*");Sleep(10);c++;
        if (c == 7){
            c=1;
        }
    }
        for(int c=1, i=8; i<=15; i++){
        color(c);
        gotoxy(75,i);printf("*");Sleep(10);c++;
        if (c == 7){
            c=1;
        }
    }
        for(int c=1, i=0, j=39, k=76;i<18;i++){
        color(c);
        gotoxy(++j,16);printf("*");
        gotoxy(--k,16);printf("*");
        Sleep(10);c++;
        if (c == 7){
            c=1;
        }
    }
    unsigned char a[30] = "     Politechnika Wroclawska  ";
    unsigned char b[30] = "       Aleksander Sozanski    ";
    unsigned char c[30] = "              226638          ";
    unsigned char d[30] = "       Wydzial Elektryczny    ";
    unsigned char e[30] = "     Kierunek Elektrotechnika ";
    unsigned char f[30] = "        Rok: II Semestr: 3    ";
    wypiszTablice(41, 9, 30, 30, a, 4);
    wypiszTablice(41, 10, 30, 30, b, 7);
    wypiszTablice(41, 11, 30, 30, c, 7);
    wypiszTablice(41, 12, 30, 30, d, 7);
    wypiszTablice(41, 13, 30, 30, e, 7);
    wypiszTablice(41, 14, 30, 30, f, 7);
    }
    void szybka_tabelka()
    {
    system("cls");
        gotoxy(30,5);
        for(int j=0;j<60;j++)
        {
            printf("*");
        }
        for(int j=5;j<=20;j++)
        {
            gotoxy(30,j);printf("*");
            gotoxy(90,j);printf("*");
        }
        gotoxy(30,20);
        for(int j=0;j<60;j++)
        {
            printf("*");
        }
    }
    void menu()
    {
    szybka_tabelka();
    char n;
    unsigned char g[30] = "       Przejdz do zadania:    ";
    unsigned char h[30] = " * 1. Zadanie 1               ";
    unsigned char i[30] = " * 2. Zadanie 2               ";
    unsigned char j[30] = " * 3.                         ";
    unsigned char k[30] = " * 4.                         ";
    unsigned char l[30] = " * 5.                         ";
    unsigned char m[30] = " * Esc. Wyjdz                 ";

    wypiszTablice(42, 6, 0, 30, g, 7);
    wypiszTablice(42, 8, 0, 30, h, 7);
    wypiszTablice(42, 10, 0, 30, i, 7);
    wypiszTablice(42, 12, 0, 30, j, 7);
    wypiszTablice(42, 14, 0, 30, k, 7);
    wypiszTablice(42, 16, 0, 30, l, 7);
    wypiszTablice(42, 18, 0, 30, m, 7);

    gotoxy(44,22);
    printf("Dokonaj wyboru: ");
    n=_getche();
    switch(n){
            case '1':
                system("cls");
                zadanie1();
            case '2':
                system("cls");
                zadanie2();
            case '3':
                system("cls");
                placeHolder();
            case '4':
                system("cls");
                placeHolder();
            case '5':
                system("cls");
                placeHolder();
            case 27 :
                exit(0);
    default:
        color(4);
        printf("\n\a\t\t\t Bledny wybor!!");
        color(7);
        Sleep(1000);
        system("cls");
        szybka_tabelka();
        menu();
        }
    }
    void stop_przycisk(void funkcja())
    {
    char n;
        color(7);
        printf("\n\tChcesz wprowadzic dane ponownie? (t/n)");
        n=_getche();
        switch(n)
        {
            case 't':
                system("cls");
                funkcja();
            case 'n':
                break;
            default:
                stop_przycisk(funkcja);
    }
    }
    void ornament()
    {
        printf("\n");
        for(int j=0;j<110;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    void placeHolder()
    {
        gotoxy(42,12);
        printf("Aktualnie puste, czeka na swoja kolej...");
        Sleep(2000);
        szybka_tabelka();
        menu();
    }

/* Ponizej znajduja sie funkcje, mieszczace w sobie tresci zadan.
Dlatego postanowilem je tu upchnac i wywolac, kiedy tego potrzebuje. */

void trescZadania1()
{
    printf("Korzystajac z przedstawionego na wykladzie algorytmu, \
    \nnapisz program umozliwiajacy konwersje liczb rzeczywistych  \
    \nna reprezentacje zmiennopozycyjna w znormalizowanym formacie\
    \nIEEE-745 dla dowolnego slowa maszynowego o szerokosci \"d\" \
    \nz okreslona liczba bitow dla mantysy \"t\". ");
}
void trescZadania2()
{
    printf("Wykorzystujac przedstawiony na wykladzie algorytm     \
    \nopracowac funkcje wyznaczania przyblizonej wartosci epsilona\
    \nmaszynowego dla dowolnej liczby zmiennopozycyjnej. Prosze   \
    \npamietac, ze podczas wyznaczania epsilona dla danego typu   \
    \nzmiennopozycyjnego, wszystkie deklaracje zmiennych          \
    \nrzeczywistych globalnych, lokalnych oraz funkcji musza byc  \
    \ntego samego typu !");
}
