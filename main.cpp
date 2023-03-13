#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
//blad w petli- jedna kolejka za malo
// nie dolicza par na sumie i nie nalicza premii
//i nie mowi kto wygra³
using namespace std;

class Tkosc
{
private:

int Tab[5];

int rzut(int i)
{
    Tab[i] = ((rand()%6)+1);
    return Tab[i];
}

void sortowanie(Tkosc &p)
{
int n=5;
    do
    {
        for (int i = 0; i < n-1; ++i)
        {
           if (p.Tab[i] > p.Tab[i+1])
            swap(p.Tab[i], p.Tab[i+1]);
        }
        n=n-1;
    }while(n>1);
}

public:

Tkosc()
{
    Tab[0]=1;
    Tab[1]=1;
    Tab[2]=1;
    Tab[3]=1;
    Tab[4]=1;
}

Tkosc(int a0, int a1, int a2, int a3, int a4)
{
    Tab[0]=a0;
    Tab[1]=a1;
    Tab[2]=a2;
    Tab[3]=a3;
    Tab[4]=a4;
}

~Tkosc()
{

}

friend istream& operator>> (istream &in, Tkosc &p)
{

int a;

for(int i=0; i<5; ++i)
    {
        in >> a;
      if(a!=0)
        {
        p.Tab[a-1]=p.rzut(a-1);
        }
      else
        {
        break;
        }
    }
}

friend ostream& operator<< (ostream &out, const Tkosc &p)
{
    for(int i=0; i<5; ++i)
        {
            out << "[" << p.Tab[i] << "]" << " ";
        }
            out << endl;

    return out;
}

int rzut1()
{
    srand (time(NULL));
    for(int i = 0; i < 5; ++i)
        {
        Tab[i] = rzut(i);
        }
    return Tab[5];
}


// FIGURY TABELA 1.

int sjedynki(Tkosc A)
{
    int a;
    a=0;

    for(int i=0; i<5; ++i)
    {
        if(A.Tab[i] == 1)
        {
            a = a + 1;
        }
    }
    return a;
}

int sdwojki(Tkosc A)
{
    int a;
    a=0;

    for(int i=0; i<5; ++i)
    {
        if(A.Tab[i] == 2)
        {
            a = a + 2;
        }
    }
    return a;
}

int strojki(Tkosc A)
{
    int a;
    a=0;

    for(int i=0; i<5; ++i)
    {
        if(A.Tab[i] == 3)
        {
            a = a + 3;
        }
    }
    return a;
}

int sczworki(Tkosc A)
{
    int a;
    a=0;

    for(int i=0; i<5; ++i)
    {
        if(A.Tab[i] == 4)
        {
            a = a + 4;
        }
    }
    return a;
}

int spiatki(Tkosc A)
{
    int a;
    a=0;

    for(int i=0; i<5; ++i)
    {
        if(A.Tab[i] == 5)
        {
            a = a + 5;
        }
    }
    return a;
}
int sszostki(Tkosc A)
{
    int a;
    a=0;

    for(int i=0; i<5; ++i)
    {
        if(A.Tab[i] == 6)
        {
            a = a + 6;
        }
    }
    return a;
}

// FIGURY TABELA 2.

int pary(Tkosc &A, int b)
{
    int a;
    a = 25;
    sortowanie(A);
    if(  ( (A.Tab[0] == A.Tab[1]) && (A.Tab[2] == A.Tab[3]) ) || ( (A.Tab[0] == A.Tab[1]) && (A.Tab[3] == A.Tab[4]) ) || ( (A.Tab[1] == A.Tab[2]) && (A.Tab[3] == A.Tab[4]) )   )
        {
        return a - 5*b;
        }

    else
        {
        cout << "To nie sa dwie pary! KARA!!! Dostajesz 0 punktow!!\n";
        return 0;
        }
}

int trojka(Tkosc &A, int b)
{
    int a;
    a = 35;
    sortowanie(A);
    if ( ( (A.Tab[0] == A.Tab[1] )&&( A.Tab[1] == A.Tab[2] ) ) || ( (A.Tab[1] == A.Tab[2])&&(A.Tab[2] == A.Tab[3]) ) || ( (A.Tab[2] == A.Tab[3]) && (A.Tab[3] == A.Tab[4]) ) )
    {
        return a - 5*b;
    }

    else
        {
        cout << "To nie sa trzy takie same! KARA!!! Dostajesz 0 punktow!!\n";
        return 0;
        }
}

int czworka(Tkosc &A, int b)
{
    int a;
    a = 40;
    sortowanie(A);
    if ( ( (A.Tab[0] == A.Tab[1]) && (A.Tab[1] == A.Tab[2])&& (A.Tab[2] == A.Tab[3]) ) || ( (A.Tab[1] == A.Tab[2]) && (A.Tab[2] == A.Tab[3]) && (A.Tab[3]== A.Tab[4]) ) )
    {
        return a - 5*b;
    }
    else
        {
        cout << "To nie sa cztery takie same! KARA!!! Dostajesz 0 punktow!!\n";
        return 0;
        }
}

int piatka(Tkosc &A, int b)
{
    int a;
    a = 50;
    sortowanie(A);
    if ( ( (A.Tab[0] == A.Tab[1]) && (A.Tab[1] == A.Tab[2])&& (A.Tab[2] == A.Tab[3]) && (A.Tab[3] == A.Tab[4]) ) )
    {
        return a - 5*b;
    }
    else
        {
        cout << "To nie jest piec takich samych! KARA!!! Dostajesz 0 punktow!!\n";
        return 0;
        }
}

int full(Tkosc &A, int b)
{
    sortowanie(A);
    if( (A.Tab[0]==A.Tab[1]) && ((A.Tab[2] == A.Tab[3]) &&(A.Tab[3]==A.Tab[4])) ||(A.Tab[3]==A.Tab[4]) && ((A.Tab[0] == A.Tab[1]) &&(A.Tab[1]==A.Tab[2])))
    {
        return 40 - 5*b;
    }
    else
        {
        cout << "To nie jest full! KARA!!! Dostajesz 0 punktow!!\n";
        return 0;
        }
}

int strit(Tkosc &A, int b)
{
    int a;
    a = 40;
    sortowanie(A);
    if ( ( (A.Tab[0] == 1 && A.Tab[1] == 2 && A.Tab[2] == 3 && A.Tab[3] == 4 && A.Tab[4] == 5) ) || ( (A.Tab[0] == 2 && A.Tab[1] == 3 && A.Tab[2] == 4 && A.Tab[3] == 5 && A.Tab[4] == 6) ) )
    {
        return a - 5*b;
    }
    else
        {
        cout << "To nie jest strit! KARA!!! Dostajesz 0 punktow!!\n";
        return 0;
        }
}

int szansa(Tkosc &A)
{
    int a;
    a = A.Tab[0] + A.Tab[1] + A.Tab[2] + A.Tab[3] + A.Tab[4];
    return a;
}

};
// KLASA TABELI WYNIKOW (DZIEDZICZENIE)
class TTab : private Tkosc
{
private:

Tkosc p;
int n;

string Tab1[9][1];
int Tab2[9][3];
string Tab3[9][1];
int Tab4[9][3];

public:

TTab()
{

Tab1[0][0] = "Gracze:          ";
Tab1[1][0] = "1. Jedynki:      ";
Tab1[2][0] = "2. Dwojki:       ";
Tab1[3][0] = "3. Trojki:       ";
Tab1[4][0] = "4. Czworki:      ";
Tab1[5][0] = "5. Piatki:       ";
Tab1[6][0] = "6. Szostki:      ";
Tab1[7][0] = "Premia:          ";
Tab1[8][0] = "Suma 1:          ";
//===========================
Tab3[0][0] = "7. Dwie pary     ";
Tab3[1][0] = "8. Trzy te same  ";
Tab3[2][0] = "9. Cztery te same";
Tab3[3][0] = "10. Piec te same  ";
Tab3[4][0] = "11. Full          ";
Tab3[5][0] = "12. Strit         ";
Tab3[6][0] = "13. Szansa        ";
Tab3[7][0] = "Suma 2:          ";
Tab3[8][0] = "SUMA:            ";
//===========================
for(int i=0; i<3; ++i)
{
  for(int j=0; j<9; ++j)
  {
    Tab2[j][i] = 0;
    Tab4[j][i] = 0;
  }
}

Tab2[0][0] = 1;
Tab2[0][1] = 2;
Tab2[0][2] = 3;


}


friend ostream& operator<< (ostream &out, const TTab &p)
{
    for(int i=0; i<9; ++i)
    {
       out << "|" << p.Tab1[i][0] << "|";
        for(int j=0; j<3; ++j)
        {
        out << " " <<p.Tab2[i][j] << " |" ;
        }
        out << "\n" << "__________________________________" << "\n";

    }
    out << "==================================" << "\n";
        for(int i=0; i<9; ++i)
    {
       out << "|" <<  p.Tab3[i][0] << "|";
        for(int j=0; j<3; ++j)
        {
        out << " " << p.Tab4[i][j] << " |" ;
        }
        out << "\n" << "__________________________________" << "\n";
    }
    return out;

}

void premia(TTab &A)
{
    int a;

    a =  A.Tab2[1][1] + A.Tab2[2][1] + A.Tab2[3][1] + A.Tab2[4][1] + A.Tab2[5][1] + A.Tab2[6][1];

    if(a>=60)
        {
        A.Tab2[7][1] = 20;
        }
    else
        {
        A.Tab2[7][1] = 0;
        }

}

void suma1(TTab &A)
{
    for(int i=0; i<3; ++i)
    A.Tab2[8][i] =  A.Tab2[1][i] + A.Tab2[2][i] + A.Tab2[3][i] + A.Tab2[4][i] + A.Tab2[5][i] + A.Tab2[6][i] + A.Tab2[7][i] ;
}

void suma2(TTab &A)
{
    for(int i=0; i<3; ++i)
    A.Tab4[7][i] =  A.Tab4[1][i] + A.Tab4[2][i] + A.Tab4[3][i] + A.Tab4[4][i] + A.Tab4[5][i] + A.Tab4[6][i] ;
}

void suma3(TTab &A)
{
    for(int i=0; i<3; ++i)
    A.Tab4[8][i] =  A.Tab2[8][i] + A.Tab4[7][i] ;
}

// Ladnie dziala
int wybor(int a, int g, Tkosc p, int n)
{
    if(a==1)
    {
        Tab2[a][g] = sjedynki(p);
    }
    if(a==2)
    {
        Tab2[a][g] = sdwojki(p);
    }

    if(a==3)
    {
       Tab2[a][g] = strojki(p);
    }

    if(a==4)
    {
        Tab2[a][g] = sczworki(p);
    }
    if(a==5)
    {
        Tab2[a][g] = spiatki(p);
    }

    if(a==6)
    {
        Tab2[a][g] = sszostki(p);
    }



    if(a==7)
    {
        Tab4[0][g] = pary(p,n);
    }

    if(a==8)
    {
        Tab4[1][g] = trojka(p,n);
    }

    if(a==9)
    {
        Tab4[2][g] = czworka(p,n);
    }

    if(a==10)
    {
        Tab4[3][g] = piatka(p,n);
    }

    if(a==11)
    {
        Tab4[4][g] = full(p,n);
    }

    if(a==12)
    {
        Tab4[5][g] = strit(p,n);
    }

    if(a==13)
    {
        Tab4[6][g] = szansa(p);
    }
}

};


int main()
{
    Tkosc A;
    TTab B;
    int g,choice,choice1,nosnik,d1,d2,w;

    nosnik = 0;

    do{
        cout << endl;
        cout << "MENU. Wybierz numer od 1 do 5" << endl;
        cout << "1. START " << endl;
        cout << "2. INSTRUKCJA " << endl;
        cout << "3. AUTORZY " << endl;
        cout << "4. FIGURY " << endl;
        cout << "5. ZAKONCZ " << endl;

        cin >> choice;

        switch(choice){

        case 1:

            for(int k=0; k<12; ++k)
            {
                for(g = 0; g<3; ++g)
                {
                    cout << "Gracz:" << g + 1 << endl;
                    A.rzut1();
                    cout << A;
                    cout << "Czy chcesz wymienic jakies kosci?\n1. Tak\n2. Nie\n";
                    cin >> d1;
                    if(d1==1)
                    {
                        nosnik=nosnik+1;
                        cin >> A;
                        cout << A;
                        cout << "Czy chcesz wymienic jakies kosci?\n1. Tak\n2. Nie\n";
                        cin >> d2;
                        if(d2==1)
                        {
                            nosnik=nosnik+1;
                            cin >> A;
                            cout << A;
                        }
                        if(d2==2)
                        {
                            nosnik=nosnik;
                        }
                    }
                    if(d1==2)
                    {
                        nosnik=nosnik;
                    }
                    cout << B;
                    cout << "Gdzie chcesz wpisac wynik rzutu? \n1. Jedynki                    2. Dwojki\n3. Trojki                     4. Czworki\n5. Piatki                     6. Szostki \n7. Dwie pary                  8. Trzy takie same\n9. Cztery takie same          10. Piec takich samych\n11. Full                      12. Strit\n13. Szansa\n";
                    cin >> w;
                    B.wybor(w,g,A,nosnik);
                    B.suma1(B);
                    B.suma2(B);
                    B.suma3(B);
                    cout << B;
                    nosnik=0;
                }
            }
            do{
                cout << endl << "Powrot- wcisnij: 9." << endl;
                cin >> choice1;

                switch(choice1){
                case 0:
                    break;
                default:
                    break;
                }
            }while(choice1!=9);

            break;

        case 2:

            cout << "Gra w kosci""\n""\n"
                    "Cel gry: Zdobyc jak najwiecej punktow i miec przy tym jak najwiecej zabawy :).""\n""\n"
                    "Przebieg gry: Gra przeznaczona jest dla 3 osob.""\nNa jedna kolejke skladaja sie 'trzy' rzuty, tzn. jeden rzut wlasciwy - 5 kosciami i dwa rzuty - wybrana liczba kosci (0-5).""\n""\n"
                    "Gre rozpoczyna  gracz 1. Pierwszy rzut wyswietli sie automatycznie, nastepnie gracz ma mozliwosc wymiany kosci, wpisujac miejsca kosci do wymiany.""\n""\n"
                    "Przyklad: gracz 1 wyrzucil [2] [3] [4] [1] [1] i chce wymienic kosc o wartosci 1. W tym celu wybiera miejsce 4 lub 5. Aby zakonczyc wybor nalezy wcisnac 0. ""\n""\n"
                    "Nastepuje rzut drugi i wyswietlaja sie 'poprawione' kosci, ktore gracz znowu moze wymienic - ostatni raz w tej turze (analogicznie jak poprzednio).""\n""\n"
                    "Na koniec zostalo wpisac wynik do tabelki, ktora sie wyswietli pod spodem razem z instrukcja.""\n""\n"
                    "Przyklad: Jezeli chcesz wybrac 'Dwie pary' - wcisnij 7.""\n""\n"
                    "Tak oto minela pierwsza kolejka gracza 1. ""\n""\n"
                    "Nastepny rzuca gracz 2, a po nim gracz 3 (ich kolejki wygladaja analogicznie). Gra trwa do momentu uzupelnienia calej tabeli.""\n""\n"
                    "Figury w tabeli: Tabele mozna podzielic na dwie czesci.""\n""\n"
                    "Pierwsza czesc sklada sie z wierszy podpisanych: jedynki, dwojki,..., szostki. W tej czesci nie jest wazna ilosc wykonanych rzutow przed uzyskaniem pozadanego efektu" "\n(jak to bedzie w drugej czesci).  Punkty liczone sa przez zsumowanie oczek z odpowiednich kosci.""\n""\n"
                    "Przyklad:  gracz po trzecim rzucie uzyskal [5] [5] [5] [2] [3] i chce wpisac 'piatki', w takim razie otrzyma 15 punktow, bo  wyrzucil trzy*5.""\n""\n"
                    "Mozliwe jest uzyskanie premii, poprzez otrzymanie w sumie 60 lub wiecej punktow w pierwszej czesci tabeli.""\n""\n"
                    "Druga czesc tabeli sklada sie z figur 'pokerowych', za ktore liczba punktow jest z gory ustalona i zmienia sie w zaleznosci od tego, ile razy gracz wymienial kosci. Jezeli gracz zdecydowal wymienic sie jeden raz swoje kosci otrzyma -5 punktow od ustalonej wartosci, a jezeli dwa razy to -10 punktow.""\n""\n"
                    "Przyklad: za full'a mozna otrzymac maksymalnie 40 punktow, i tyle sie otrzyma gdy  w  drugm i tzrecim rzucze nie zmieni sie zadnej kosci, gdy zmienimy jakies kosci to otrzymamy odpowidnieo 35 punktow za jedno podmienienie lub 30 za podmienienie kosci dwa razy.""\n""\n"
                    "Wyjatek: 'Szansa' to nasze kolo ratunkowe, ktore zlicza liczbe wszystkich oczek na wyrzuconych kosciach, nie wazne co wyrzucimy i w ktorej kolejce.""\n""\n"
                    "Za oszustwo czeka Cie kara!!!\n\n";
            do{
                cout << endl << "Powrot- wcisnij: 9." << endl;
                cin >> choice1;

                switch(choice1){
                case 0:
                    break;
                default:
                    break;
                }
            }while(choice1!=9);

            break;

        case 3:

            cout << "1. Magdalena Wawrzyniak \n2. Tomasz Szmyd";
            do{
                cout << endl << "Powrot- wcisnij: 9." << endl;
                cin >> choice1;

                switch(choice1){
                case 0:
                    break;
                default:
                    break;
                }
            }while(choice1!=9);

            break;

        case 4:

            cout << "Figury (kosci moga byc ulozone w dowolnej kolejnosci, byleby spelnialy ponizsze warunki)\n\nJedynki - suma jedynek na wyrzuconych kosciach;\n\nDwojki - suma dwojek na wyrzuconych kosciach;\n\nTrojki - suma trojek na wyrzuconych kosciach;\n\nCzworki - suma czworek na wyrzuconych kosciach;\n\nPiatki - suma piatek na wyrzuconych kosciach;\n\nSzostki - suma szostek na wyrzuconych kosciach;\n\nDwie pary (25 pkt) - 2 takie same kosci + 2 takie same wyrzucone kosci + 1 dowolna kosc;\n\nTrzy takie same (35 pkt) - 3 takie same kosci + 2 dowolne;\n\nCztery takie same (40 pkt) - 4 takie same kosci + 1 dowolna;\n\nPiec takich samych (50 pkt) - 5 takich samych kosci;\n\nFull (40 pkt) - 3 takie same kosci + 2 takie same kosci;\n\nStrit (40 pkt) - wszystkie kosci rozne;\n\nSzansa - suma wszystkich oczek.  \n";
            do{
                cout << endl << "Powrot- wcisnij: 9." << endl;
                cin >> choice1;

                switch(choice1){
                case 0:
                    break;
                default:
                    break;
                }
            }while(choice1!=9);

            break;
        case 5:
        cout << "Do zobaczenia!" << endl;
        break;
    } // Zamkniecie switch
    } // Zamkniecie do
while(choice!=5);

return 0;
}
