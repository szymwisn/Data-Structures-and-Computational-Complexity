#include "Menu.h"
#include "Table.h"
#include "List.h"

void Menu::displayMenu(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Usun" << endl;
    cout << "3.Dodaj" << endl;
    cout << "4.Znajdz" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "7.Test (pomiary)" << endl;
    cout << "0.Powrot do menu" << endl;
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
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myTab.loadFromFile(fileName);
                myTab.display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                myTab.deleteFromTable(index);
                myTab.display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                myTab.addValue(index,value);
                myTab.display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (myTab.IsValueInTable(value))
                    cout << "podana wartosc jest w tablicy";
                else
                    cout << "podanej wartosci NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                myTab.generateTable(value);
                myTab.display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                myTab.display();
                break;

            case '7': //TODO tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
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
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  listy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                myList.loadFromFile(fileName);
                myList.display();
                break;

            case '2': //tutaj usuwanie elemenu z listy
                cout << " podaj index:";
                cin >> value;
                myList.deleteFromList(value);
                myList.display();
                break;

            case '3': //tutaj dodawanie elemetu do listy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                myList.addValue(index,value);
                myList.display();
                break;

            case '4': //tutaj znajdowanie elemetu w liscie
                cout << " podaj wartosc:";
                cin >> value;
                if (myList.IsValueInList(value))
                    cout << "podana wartosc jest w liscie";
                else
                    cout << "podanej wartosci NIE ma w liscie";
                break;

            case '5':  //tutaj generowanie listy
                cout << "Podaj ilosc elementow listy:";
                cin >> value;
                myList.generateList(value);
                myList.display();
                break;

            case '6':  //tutaj wyświetlanie listy
                myList.display();
                break;

            case '7': //TODO tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne case'y
                break;
        }

    } while (opt != '0');
}

void Menu::menu_heap()
{
    //analogicznie jak menu_table()
}
