#include "Menu.h"
#include "Table.h"
#include "List.h"
#include "Heap.h"

void Menu::displayMenu(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1. Wczytaj z pliku" << endl;
    cout << "2. Usun w wybranym miejscu" << endl;
    cout << "3. Usun na poczatku" << endl;
    cout << "4. Usun na koncu" << endl;
    cout << "5. Usun w losowym miejscu" << endl;
    cout << "6. Dodaj w wybranym miejscu" << endl;
    cout << "7. Dodaj na poczatku" << endl;
    cout << "8. Dodaj na koncu" << endl;
    cout << "9. Dodaj w losowym miejscu" << endl;
    cout << "q. Znajdz" << endl;
    cout << "w. Utworz losowo" << endl;
    cout << "e. Wyswietl" << endl;
    cout << "r. Test (pomiary)" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Menu::displayMenuHeap(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1. Wczytaj z pliku" << endl;
    cout << "2. Usun w wybranym miejscu" << endl;
    cout << "3. Dodaj" << endl;
    cout << "4. Znajdz" << endl;
    cout << "5. Utworz losowo" << endl;
    cout << "6. Wyswietl" << endl;
    cout << "7. Test (pomiary)" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Menu::menu_table()
{
    Table myTab;

    char opt;
    string fileName;
    int index, value;

    do{
        displayMenu("--- TABLICA ---");
        cin >> opt;
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myTab.loadFromFile(fileName);
                myTab.display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy w wybranym miejscu
                cout << " podaj index:";
                cin >> index;
                myTab.deleteFromTable(index);
                myTab.display();
                break;

            case '3': //tutaj usuwanie elemenu z tablicy na poczatku
                myTab.deleteFromTableStart();
                myTab.display();
                break;

            case '4': //tutaj usuwanie elemenu z tablicy na koncu
                myTab.deleteFromTableEnd();
                myTab.display();
                break;

            case '5': //tutaj usuwanie elemenu z tablicy w losowym miejscu
                myTab.deleteFromTableRandom();
                myTab.display();
                break;

            case '6': //tutaj dodawanie elemetu w wybrane miejsce do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                myTab.addValue(index,value);
                myTab.display();
                break;

            case '7': //tutaj dodawanie pierwszego elemetu do tablicy
                cout << " podaj wartosc:";
                cin >> value;

                myTab.addValueStart(value);
                myTab.display();
                break;

            case '8': //tutaj dodawanie ostatniego elemetu do tablicy
                cout << " podaj wartosc:";
                cin >> value;

                myTab.addValueEnd(value);
                myTab.display();
                break;

            case '9': //tutaj dodawanie losowego elemetu do tablicy
                cout << " podaj wartosc:";
                cin >> value;

                myTab.addValueRandom(value);
                myTab.display();
                break;

            case 'q': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (myTab.IsValueInTable(value))
                    cout << "podana wartosc jest w tablicy";
                else
                    cout << "podanej wartosci NIE ma w tablicy";
                break;

            case 'w':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                myTab.generateTable(value);
                myTab.display();
                break;

            case 'e':  //tutaj wyświetlanie tablicy
                myTab.display();
                break;

            case 'r': //TODO tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne case'y
                break;
        }

    } while (opt != '0');
}

void Menu::menu_list()
{
    List myList;

    char opt;
    string fileName;
    int index, value;

    do{
        displayMenu("--- LISTA DWUKIERUNKOWA ---");
        cin >> opt;
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie listy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myList.loadFromFile(fileName);
                myList.display();
                break;

            case '2': //tutaj usuwanie elementu o podanej wartosci z listy
                cout << " podaj wartosc:";
                cin >> value;
                myList.deleteFromList(value);
                myList.display();
                break;

            case '3': //tutaj usuwanie elemenu z poczatku listy
                myList.deleteFromListStart();
                myList.display();
                break;

            case '4': //tutaj usuwanie elemenu z konca listy
                myList.deleteFromListEnd();
                myList.display();
                break;

            case '5': //tutaj usuwanie elemenu z losowego miejsca listy
                myList.deleteFromListRandom();
                myList.display();
                break;

            case '6': //tutaj dodawanie elemetu w wybrane miejsce do listy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                myList.addValue(index,value);
                myList.display();
                break;

            case '7': //tutaj dodawanie pierwszego elemetu do listy
                cout << " podaj wartosc:";
                cin >> value;

                myList.addValueStart(value);
                myList.display();
                break;

            case '8': //tutaj dodawanie ostatniego elemetu do listy
                cout << " podaj wartosc:";
                cin >> value;

                myList.addValueEnd(value);
                myList.display();
                break;

            case '9': //tutaj dodawanie losowego elemetu do listy
                cout << " podaj wartosc:";
                cin >> value;

                myList.addValueRandom(value);
                myList.display();
                break;

            case 'q': //tutaj znajdowanie elemetu w liscie
                cout << " podaj wartosc:";
                cin >> value;
                if (myList.IsValueInList(value))
                    cout << "podana wartosc jest w liscie";
                else
                    cout << "podanej wartosci NIE ma w liscie";
                break;

            case 'w':  //tutaj generowanie listy
                cout << "Podaj ilosc elementow listy:";
                cin >> value;
                myList.generateList(value);
                myList.display();
                break;

            case 'e':  //tutaj wyświetlanie listy
                myList.display();
                break;

            case 'r': //TODO tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne case'y
                break;
        }

    } while (opt != '0');
}

void Menu::menu_heap()
{
    Heap myHeap;

    char opt;
    string fileName;
    int index, value;

    do{
        displayMenuHeap("--- KOPIEC BINARNY (MAX) ---");
        cin >> opt;
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  kopca z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myHeap.loadFromFile(fileName);
                myHeap.display();
                break;

            case '2': //tutaj usuwanie elemenu z kopca
                cout << " podaj wartosc:";
                cin >> value;
                myHeap.deleteFromHeap(value);
                myHeap.display();
                break;

            case '3': //tutaj dodawanie elemetu do kopca
                cout << " podaj wartosc:";
                cin >> value;

                myHeap.addValue(value);
                myHeap.display();
                break;

            case '4': //tutaj znajdowanie elemetu w kopcu
                cout << " podaj wartosc:";
                cin >> value;
                if (myHeap.IsValueInHeap(value))
                    cout << "podana wartosc jest w kopcu";
                else
                    cout << "podanej wartosci NIE ma w kopcu";
                break;

            case '5':  //tutaj generowanie kopca
                cout << "Podaj ilosc elementow kopca:";
                cin >> value;
                myHeap.generateHeap(value);
                myHeap.display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                myHeap.display();
                break;

            case '7': //TODO tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne case'y
                break;
        }

    } while (opt != '0');
}
