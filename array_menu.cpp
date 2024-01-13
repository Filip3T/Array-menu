#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int randint(int p, int k) {
    return int((k - p) * (double)rand() / RAND_MAX) + p;
}
int main()
{
    srand(time(NULL));                               ///przelatywanie przez randy
    for (int i = 0; i < 100; i++) {
        rand();
    }
    bool aktywny = true;
    int* p = new int[4];                             ///stworzenie tablicy
    int* np = NULL;
    for (int i = 0; i < 4; i++) {
        p[i] = randint(1, 30);
    }
    int size = 4;
    while (aktywny) {                                ///while aktywnosc
        cout << "1: Dodaj element" << endl;          ///interfejs
        cout << "2: Usun element" << endl;
        cout << "3: Wsadz element" << endl;
        cout << "4: Pokaz elementy" << endl;
        cout << "5: Zapisz" << endl;
        cout << "6: Wczytaj" << endl;
        cout << "7: Wyjdz" << endl;
        cout << "Wybor: ";
        int c;                                       ///wybor
        cin >> c;
        cout << endl;
        switch (c) {                                 ///switch z wyborem
        default:
            system("cls");
            break;
        case 7:
            aktywny = false;
            break;
        case 1:                                                                 //dodaj
        {
            np = new int[size + 1];
            for (int i = 0; i < size; i++) {
                np[i] = p[i];
            }
            system("cls");
            cout << "Nowa wartosc: ";
            int nowa;
            cin >> nowa;
            system("cls");
            np[size] = nowa;
            delete[] p;
            size++;
            p = new int[size];
            for (int i = 0; i < size; i++) {
                p[i] = np[i];
            }
            delete[] np;
        }
        break;
        case 2:                                                                 //usun
        {
            int element;
            cout << "Ktory element chcesz usunac?: ";
            cin >> element;
            cout << endl;
            np = new int[size - 1];
            int iter = 0;
            for (int i = 0; i < size; i++) {
                if (i != element - 1) {
                    np[iter] = p[i];
                    iter += 1;
                }
            }
            system("cls");
            size--;
            for (int i = 0; i < size; i++) {
                p[i] = np[i];
            }
            delete[] np;
        }
        break;
        case 3:                                                                 //wsadz
        {
            system("cls");
            cout << "gdzie chcesz dodac element?: ";
            int place = 0;
            cin >> place;
            system("cls");
            cout << "Jaki element chcesz dodac?: ";
            int element = 0;
            cin >> element;
            system("cls");
            np = new int[size + 1];
            int iter = 0;
            for (int i = 0; i <= size; i++) {
                if (i != place - 1) {
                    np[i] = p[iter];
                    iter++;
                }
                else {
                    np[i] = element;
                }
            }
            size++;
            delete[] p;
            p = new int[size];
            for (int i = 0; i < size; i++) {
                p[i] = np[i];
            }
            delete[] np;
        }
        break;
        case 4:                                                                 //pokaz
        {
            for (int i = 0; i < size; i++) {
                cout << p[i] << "  ";
            }
            cout << endl << "zakoncz: ";
            int breakout;                                               //mozna wpisac byle co zeby zakonczyc ogladanie elementow :D
            cin >> breakout;
            system("cls");
        }
        break;
        case 5:                                                                 //zapisz
        {
            fstream plik;
            plik.open("C:\\Users\\Boss\\Desktop\\dane.txt", ios::out | ios::trunc);

            if (plik.is_open()) {
                plik << size << endl;
                for (int i = 0; i < size; i++) {
                    plik << p[i] << endl;
                }
                plik.close();
            }
            else {
                cout << "Nie udalo sie otworzyc pliku" << endl;
            }
            system("cls");
        } // case
        break;
        case 6:                                                                 //wczytaj
        {
            fstream plik;
            plik.open("C:\\Users\\Boss\\Desktop\\dane.txt", ios::in);
            if (plik.is_open()) {
                system("cls");
                string temp;
                delete[] p;
                int i = 0;
                while (getline(plik, temp)) {
                    if (i == 0) {
                        size = atoi(temp.c_str());
                        p = new int[size];
                    }
                    else {
                        p[i - 1] = atoi(temp.c_str());
                    }
                    i++;
                }
                plik.close();
            }
            else {
                cout << "Nie udalo sie otworzyc pliku" << endl;
            }
        } //case
        break;
        } // *switch
    } // *while
    delete[] p;
    return 1;
} // *main
