#include<conio.h>
#include<string>
#include<iostream>
#include "Menu.h"

using namespace std;

Menu menu;

int main(int argc, char* argv[])
{
    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1. Tablica" << endl;
        cout << "2. Lista" << endl;
        cout << "3. Kopiec" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Podaj opcje:";
        option = getche();
        cout << endl;

        switch (option){
            case '1':
                menu.menu_table();
                break;

            case '2':
                menu.menu_list();
                break;

            case '3':
                menu.menu_heap();
                break;

            default:
                break;
        }

    } while (option != '0');

    return 0;
}
