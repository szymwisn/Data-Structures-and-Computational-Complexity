#include "Menu.h"

Menu menu;

int main(int argc, char* argv[])
{
    // dzieki temu rand nie bedzie generowalo zawsze tej samej sekwencji liczb
    srand(time(NULL));

    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1. Tablica" << endl;
        cout << "2. Lista" << endl;
        cout << "3. Kopiec" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        //option = getche();
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
