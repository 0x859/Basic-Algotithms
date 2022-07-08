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
void trescZadania3();
void trescZadania4();
void ornament();
void stop_przycisk(void funkcja());

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
    char tab1[64],tab2[64],tab3[64];
    float a, liczba, rzeczywista, ulamek;
    int t = 0, e, c, bias, d, bitexp, bm, znak, mantysa, wykladnik, cala, l = 0;
    printf("\n\tWprowadz liczbe rzeczywista do konwersji: ");
    scanf("%f", &a);
    while(a == 0)
    {
        printf("\tPodana liczba musi byc rozna od. 0 :)");
        printf("\n\tWprowadz liczbe rzeczywista do konwersji: ");
        scanf("%f", &a);
    }
    if (a > 0)
    {
        znak = 0;
    }
    else
    {
        znak = 1;
    }
    printf("\n\tPodaj szerokosc slowa maszynowego (d): ");
	scanf("%d",&d);
	printf("\n\tPodaj Liczbe bitow dla mantysy bm = ");
	scanf("%d",&bm);
    bitexp = d - bm - znak;
    liczba = 1;
    wykladnik = bitexp - 1;
    for (int i = 0; i < wykladnik; i++)
    {
        liczba *= 2;
    }
    bias = liczba - 1;
    
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
    printf("\n\tReprezentacja binarna czesci ulamkowej: ");
    if( a < 0)
		rzeczywista = a*(-1);
	else
		rzeczywista = a;
		
	cala = rzeczywista;
	ulamek = rzeczywista - cala;
	int i = 0;
    do
	{
		{
			ulamek *= 2;
			if (ulamek >= 1)
			{
				tab2[i] = 1;
				ulamek--;
			}
			else
				tab2[i] = 0;
		}
	i++;
	}
	while( ulamek > 0);
	cala = 0;	
	for(int j = 0;j < i;j++)
	{	
		printf("%d",tab2[j]);
	}
    printf("\n\tReprezentacja binarna czesci calkowitej: ");
    if(a < 0)
		rzeczywista= a*(-1);
	else
		rzeczywista= a;
	cala = rzeczywista;
    if(cala == 0)
		tab2[l]=0;
	else
		while(1)
		{
			if(cala == 1)
			{
				tab2[l]=1;
				break;
			}
		    int k = cala % 2;	
			if( k == 1)
			    tab2[l]=1;
			else
			    tab2[l]=0;		
		    l++;
		    cala /= 2;
		}
    i = 0;
    for(int j = l;j>=0;j--)
	{	
		tab1[i]=tab2[j];
		printf("%d", tab1[i]);
		i++;
	}
    printf("\n\tPrzesuniecie bias = %d", bias);
    printf("\n\tLiczba bitow dla cechy przesunietej E: bitexp = %d", bitexp);
    printf("\n\tLiczba rzeczywista w ukladzie pozycyjnym o podstawie 2:");
	if(a < 0)
		printf("-");
	for(int j = 0; j < (t + 1) ;j++)
	{
		tab3[j]=tab1[j];
		printf("%d",tab3[j]);
	}
	printf(".");
	for(int j, l = 0 ;l < i ;l++)
	{
		tab3[j]=tab2[l];
		printf("%d",tab3[j]);
		j++;
	}
    ornament();
    stop_przycisk(zadanie1);
    menu();
}
void zadanie2()
{
    trescZadania2();
    ornament();
    double epsilon_d = 1.0, x1;
    float epsilon_f = 1.0f, x2;
    long double epsilon_ld = 1.0, x3;
    printf("\n\tPodaj liczbe rzeczywsta: ");
    scanf("%lf", &x1);
    printf( "\n\tEpsilon;   %lf + epsilon\n", x1);
    x2 = (float) x1;
    x3 = (long double) x1;

    do 
     {
       epsilon_ld /= 2.0;
     }
    while ((x3 + (epsilon_ld/2.0)) != x3);

    do 
     {
        printf( "\t%G\t%.20f\n", epsilon_d, (x1 + epsilon_d) );
        epsilon_d /= 2.0;
     }
    while ((x1 + (epsilon_d/2.0)) != x1);

    do 
     {
       epsilon_f /= 2.0f;
     }
    while ((float)(x2 + (epsilon_f/2.0)) != x2);
    
    printf( "\n\tWyliczony epsilon maszynowy (float): %G", epsilon_f );
    printf( "\n\tWyliczony epsilon maszynowy (double): %lG", epsilon_d );
    printf( "\n\tWyliczony epsilon maszynowy (long double): %LG\n", epsilon_ld );
    ornament();
    stop_przycisk(zadanie2);
    menu();
}
void zadanie3()
{
    trescZadania3();
    ornament();
    float epsilon = 0.0, x = 0, y = 0, mantysa = 0.0, n = 0;
    int t = 0, dig = 0, pot = 1, calkowita = 0;
    printf("\n\tPodaj liczbe rzeczywsta x > 0: ");
    scanf("%f", &x);
    while(x == 0)
    {
        system("cls");
        trescZadania3();
        ornament();
        printf("\n\tPodana liczba musi byc rozna od 0.");
        printf("\n\tPodaj liczbe rzeczywsta x > 0 : ");
        scanf("%f", &x);
    }
    printf("\tZerowanie cyfr ulamkowych od pozycji t-1: ");
	scanf("%d", &t);
	printf("\tLiczba x przeznaczona do konwersji: \t%0.14E", x);

    epsilon = x;
    do
    {
        epsilon /= 2.0;
        y = x + epsilon;
    } while (x != y);
    printf("\n\tEpsilon maszynowy dla liczby x: \t%0.14E", epsilon);

    mantysa = epsilon;
    while (mantysa < 1)
    {
        mantysa *= 10;
        dig++;
    }

    if (mantysa < 4.5)
    {
        dig--;
    }
    else
    {
        dig -= 2;
    }
    printf("\n\tIlosc cyfr poprawnych w liczbie x: \t%d", dig);

    for (int i = 0; i < t; i++)
    {
        x *= 10.0;
        pot *= 10; 
    }
    calkowita = x;
    n = calkowita;
    n /= pot;
    printf("\n\tWyswietlane sa wszystkie liczby: \t%0.14E", n);
	printf("\n\tLiczba tylko z cyframi poprawnymi: \t%0.*E\n", dig, n); 
    ornament();
    stop_przycisk(zadanie3);
    menu();
}
void zadanie4()
{
    int gora, dol, lewo, prawo;
    trescZadania4();
    ornament();
    printf("\n\tWprowadz wartosci brzegowe potencjalu.\n");
    printf("\tPotencjal gorny: ");
    scanf("%d", &gora);
    printf("\tPotencjal dolny: ");
    scanf("%d", &dol);
    printf("\tPotencjal lewy: ");
    scanf("%d", &lewo);
    printf("\tPotencjal prawy: ");
    scanf("%d", &prawo);
    int licznik = 0;
    struct wezel
    {
        double v;
        char a;
    } siatka[18][18];
    int i, j;
    char koniec = '\0';
    for (i = 0; i < 18; i++)
    {
        for (j = 0; j < 18; j++)
        {
            siatka[i][j].v = 0.0;
            siatka[i][j].a = 'W';   
        }
    }
    for (i = 0; i < 18; i++)
    {
        siatka[0][i].v = gora;
        siatka[0][i].a = 'B';

        siatka[17][i].v = dol;
        siatka[17][i].a = 'B';

        siatka[i][0].v = lewo;
        siatka[i][0].a = 'B';

        siatka[i][17].v = prawo;
        siatka[i][17].a = 'B';
    }
    do
    {
        system("cls");
        trescZadania4();
        ornament();
        printf("\tWcisnij \"q\" aby zakonczyc.\n");
        for (i = 0; i < 18; i++)
        {
            for (j = 0; j < 18; j++)
            {
                printf("%6.2f", siatka[i][j].v);
            }
            printf("\n");
        }
        for (i = 1; i < 17; i++)
        {
            for (j = 1; j < 17; j++)
            {
                if (siatka[i][j].a == 'W')
                    siatka[i][j].v = 0.25*(siatka[i][j-1].v+siatka[i][j+1].v+siatka[i-1][j].v+siatka[i+1][j].v);
            }
        }
        licznik++;
        if (kbhit()) koniec = getch();
    } while (koniec != 'q' ^ licznik == 200);
    
    ornament();
    stop_przycisk(zadanie4);
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
    unsigned char j[30] = " * 3. Zadanie 3               ";
    unsigned char k[30] = " * 4. Zadanie 4               ";
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
                zadanie3();
            case '4':
                system("cls");
                zadanie4();
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
void trescZadania3()
{
    printf("Opracowac funkcje umozliwiajaca zerowanie cyfr poprawnych\
    \nliczby zmiennopozycyjnej od podanej w wywolaniu pozycji.       \
    \nDodatkowo z funkcji nalezy wyprowadzic wartosc epsilona        \
    \nmaszynowego oraz liczbe poprawnych cyfr ulamkowych dig.        \
    \nJezeli mantysa epsilona jest mniejsza od 4.5 to liczba dig     \
    \npowinna byc pomniejszona o jeden od modulu jego cechy          \
    \n(wykladnika), w przeciwnym przypadku nalezy dig zmniejszyc o dwa.");
}
void trescZadania4()
{
    printf("Opracowac program, ktory umozliwi rozwiazanie elektrostatycznego\
    \nzagadnienia Dirichleta w plaskich obszarach geometrycznych, bedacych  \
    \nprzekrojem poprzecznym ukladow nieograniczonych w trzecim wymiarze.   \
    \nZagadnienie Dirichleta dotyczy wylacznie ograniczonych obszarow       \
    \nwewnetrznych i w zadaniu sprowadza sie do rozwiazania ukladu rownan   \
    \nrozniczkowych czastkowych (kierunkowych) drugiego rzedu z okreslonymi \
    \nwarunkami brzegowymi pierwszego rodzaju (w rozpatrywanym przypadku    \
    \nzadawane sa wartosci potencjalu). ");
}