#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ileLiczb;
clock_t start, stop;
double czas;

void sortowanieBabelkowe(int *tab, int n);
void quicksort(int *tablica, int lewy, int prawy);
void scalanie(int tablica[], int start, int srodek, int koniec);
void sortowaniePrzezScalanie(int tablica[], int start, int koniec);
void selecionsort(int *tablica, int n);
void insertionsort(int *tablica, int n);
bool czyTablicaJestPosortowana(int tablica[], int n);

int main()
{
    cout << "Porownanie czasow sortowania - 5 roznych metod" << endl << endl;
    cout << "Ile losowych liczb w tablicy (z przedzialu od 1 do 100000: ";
    cin >> ileLiczb;

    int *tablica1;
    tablica1 = new int [ileLiczb];

    int *tablica2;
    tablica2 = new int [ileLiczb];

    int *tablica3;
    tablica3 = new int [ileLiczb];

    int *tablica4;
    tablica4 = new int [ileLiczb];

    int *tablica5;
    tablica5 = new int [ileLiczb];

    srand (time(NULL));
    for (int i=0; i<ileLiczb; i++)
    {
        tablica1 [i] = rand()%100000+1;
    }   // for

    for (int i=0; i<ileLiczb; i++)
    {
        tablica2 [i] = tablica1 [i];
        tablica3 [i] = tablica1 [i];
        tablica4 [i] = tablica1 [i];
        tablica5 [i] = tablica1 [i];
    }   // for

    // Sortowanie babelkowe

    cout << endl << "Sortowanie babelkowe trwa..." << endl;
    start = clock ();
    sortowanieBabelkowe (tablica1, ileLiczb);
    stop = clock ();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << endl << "Czas sortowania babelkowego: " << czas << " s" << endl;

    // Quicksort

    cout << endl << "Sortowanie Quicksort trwa..." << endl;
    start = clock ();
    quicksort (tablica2, 0, ileLiczb-1);
    stop = clock ();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << endl << "Czas sortowania Quicksort: " << czas << " s" << endl;

    // Sortowanie przez scalanie

    cout << endl << "Sortowanie przez scalanie trwa..." << endl;
    start = clock ();
    sortowaniePrzezScalanie (tablica3, 0, ileLiczb-1);
    stop = clock ();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << endl << "Czas sortowania przez scalanie: " << czas << " s" << endl;

    // Selectionsort

    cout << endl << "Sortowanie Selectionsort trwa..." << endl;
    start = clock ();
    selecionsort (tablica4, ileLiczb);
    stop = clock ();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << endl << "Czas sortowania Selectionsort: " << czas << " s" << endl;

    // Insertionsort

    cout << endl << "Sortowanie Insertionsort trwa..." << endl;
    start = clock ();
    insertionsort (tablica5, ileLiczb);
    stop = clock ();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << endl << "Czas sortowania Insertionsort: " << czas << " s" << endl;

    // Sprawdzenie poprawnosci posortowania

    if (czyTablicaJestPosortowana(tablica1,ileLiczb) == true)
        cout << "TAK. Tablica metoda sortowania babelkowego jest posortowana." << endl;
    else
        cout << "NIE. Tablica metoda sortowania babelkowego nie jest posortowana." << endl;

    if (czyTablicaJestPosortowana(tablica2,ileLiczb) == true)
        cout << "TAK. Tablica metoda sortowania quicksort jest posortowana." << endl;
    else
        cout << "NIE. Tablica metoda sortowania quicksort nie jest posortowana." << endl;

    if (czyTablicaJestPosortowana(tablica3,ileLiczb) == true)
        cout << "TAK. Tablica metoda sortowania przez scalanie jest posortowana." << endl;
    else
        cout << "NIE. Tablica metoda sortowania przez scalanie nie jest posortowana." << endl;

    if (czyTablicaJestPosortowana(tablica4,ileLiczb) == true)
        cout << "TAK. Tablica metoda sortowania selectionsort jest posortowana." << endl;
    else
        cout << "NIE. Tablica metoda sortowania selectionsort nie jest posortowana." << endl;

    if (czyTablicaJestPosortowana(tablica5,ileLiczb) == true)
        cout << "TAK. Tablica metoda sortowania insertionsort jest posortowana." << endl;
    else
        cout << "NIE. Tablica metoda sortowania insertionsort nie jest posortowana." << endl;

    delete [] tablica1;
    delete [] tablica2;
    delete [] tablica3;
    delete [] tablica4;
    delete [] tablica5;

    return 0;
}   // main

void sortowanieBabelkowe(int *tab, int n)
{
    int zmiennaTymczasowa;
    for (int i=1; i<n; i++)
    {
        for (int j=n-1; j>=i; j--)
        {

            if (tab[j]<tab[j-1])
            {
                zmiennaTymczasowa=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=zmiennaTymczasowa;
            } // if
        } // for
    } // for
} //sortowanieBabelkowe

void quicksort(int *tablica, int lewy, int prawy)
{
    int os=tablica[(lewy+prawy)/2];
    int i,j,zmiennaTymczasowa;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<os) i++;
        while (tablica[j]>os) j--;
        if (i<=j)
        {
            zmiennaTymczasowa=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=zmiennaTymczasowa;
            i++;
            j--;
        } // if
    } //  do while
    while (i<=j);
    if (j>lewy) quicksort(tablica,lewy, j);
    if (i<prawy) quicksort(tablica, i, prawy);
} // quicksort

void scalanie(int tablica[], int start, int srodek, int koniec)
{
    int *tablicaPomocnicza = new int[(koniec-start+1)]; // utworzenie tablicy pomocniczej, bylo robione na papierze i tu byl blad
    int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

    while (i <= srodek && j <= koniec)
    {
        if (tablica[j] < tablica[i])
        {
            tablicaPomocnicza[k] = tablica[j];
            j++;
        } // if
        else
        {
            tablicaPomocnicza[k] = tablica[i];
            i++;
        } // else
        k++;
    } // while

    if (i <= srodek)
    {
        while (i <= srodek)
        {
            tablicaPomocnicza[k] = tablica[i];
            i++;
            k++;
        } // while
    } // if
    else
    {
        while (j <= koniec)
        {
            tablicaPomocnicza[k] = tablica[j];
            j++;
            k++;
        } // while
    } // else

    for (i = 0; i <= koniec-start; i++)
        tablica[start+i] = tablicaPomocnicza[i];

        delete [] tablicaPomocnicza; // Jak tego zabraknie to bedzie wyciek pamieci
} // scalanie

void sortowaniePrzezScalanie(int tablica[], int start, int koniec)
{

    int srodek;

    if (start != koniec)
    {
        srodek = (start + koniec)/2;
        sortowaniePrzezScalanie(tablica, start, srodek);
        sortowaniePrzezScalanie(tablica, srodek+1, koniec);
        scalanie(tablica, start, srodek, koniec);
    } // if
} // sortowaniePrzezScalanie

void selecionsort(int *tablica, int n)
{
    int zmiennaTymczasowa, indeksWartosciMinimalnej;
    for (int i = 0; i < n; i++)
    {
        indeksWartosciMinimalnej = i;
        for (int j = i+1; j < n; j++)
        {
            if (tablica[j] < tablica[indeksWartosciMinimalnej])
                indeksWartosciMinimalnej = j;
        } // for
        zmiennaTymczasowa = tablica[indeksWartosciMinimalnej];
        tablica[indeksWartosciMinimalnej] = tablica[i];
        tablica[i] = zmiennaTymczasowa;
    } // for
} // selecionsort

void insertionsort(int *tablica, int n)
{

        int j,bierzacaWartosc;
        for (int i=1; i<n; i++)
        {
            j=i;
            bierzacaWartosc=tablica[i];
            while ((j>0) && (tablica[j-1]>bierzacaWartosc))
            {
                tablica[j]=tablica[j-1];
                j--;
            } // while
            tablica[j]=bierzacaWartosc;
        } // for
} // insertionsort

bool czyTablicaJestPosortowana(int tablica[], int n)
{
    bool posortowana = true;
    for (int i = 0; i < n-1; i++) { if (tablica[i] > tablica[i+1])
            posortowana = false;
    } // for
    return posortowana;
} // czyTablicaJestPosortowana
