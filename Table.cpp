#include "Table.h"
#include <cstdlib>
#include <ctime>

Table::Table() {
    tab = new int[0];
    size = 0;
}

int Table::loadFromFile(string FileName) {
    return 0;
}

bool Table::IsValueInTable(int val) {

    // iteruje po tablicy i sprawdza czy element tablicy jest rowny podanej wartosci
    for(int i = 0 ; i < size; i++) {
        if(tab[i] == val) {
            return true;
        }
    }

    return false;
}

void Table::addValue(int index, int value) {
    // zwiekszenie rozmiaru tablicy
    size++;

    // utworzenie nowej, tymczasowej tablicy
    temp = new int[size];

    // jesli podany index przekracza rozmiar tablicy nowy element doda sie na ostatniej pozycji
    if(index > size) {
        index = size-1;
    }

    // wstawienie liczby o danym indexie do tymczasowej tablicy
    temp[index] = value;

    // wypelnienie miejsc przed danym indexem w tymczasowej tablicy
    if(index > 0) {
        for(int i = 0; i < index; i++) {
            temp[i] = tab[i];
        }
    }

    // wypelnienie miejsc po danym indexie w tymczasowej tablicy
    // size - 1, bo na poczatku size zostal powiekszony o 1, a tu tego nie potrzebujemy
    if(index < size) {
        for(int i = index; i < size - 1; i++) {
            temp[i + 1] = tab[i];
        }
    }

    // wskaznik tablicy wskazuje teraz na nowa tablice
    tab = new int[size];
    tab = temp;
}

void Table::deleteFromTable(int index) {
    // zmniejszenie rozmiaru tablicy
    size--;

    // utworzenie nowej, tymczasowej tablicy
    temp = new int[size];

    // wypelnienie tymczasowej tablicy elementami przed danym indexem
    for(int i = 0; i < index; i++) {
        temp[i] = tab[i];
    }

    // wypelnienie tymczasowej tablicy elementami po danym indexie
    // size + 1, bo wczesniej pomniejszono o 1, a tu jeszcze potrzebujemy tego elementu
    for(int i = index; i < size + 1 ; i++) {
        temp[i] = tab[i + 1];
    }

    // wskaznik tablicy wskazuje teraz na nowa tablice
    tab = new int[size];
    tab = temp;
}

void Table::display() {
    cout << "index: wartosc" << endl;
    if(size > 0) {
        for(int i = 0; i < size; i++) {
            cout << i << ": " << tab[i] << endl;
        }
    } else {
        cout << "W tablicy nie ma zadnych elementow." << endl;
    }
}

void Table::generateTable(int size) {
    // dzieki temu rand nie bedzie generowalo zawsze tej samej sekwencji liczb
    srand(time(NULL));

    // ustawienie rozmiaru tablicy
    this->size = size;

    // utworzenie tablicy tymczasowej
    temp = new int[size];

    // wypelnienie tablicy tymczasowej losowymi elementami
    for(int i = 0; i < size; i++) {
        temp[i] = (rand() % 10) + 1; // zakres <1, 10>
    }

    // przypisanie wskaznika tablicy wlasciwej na wskaznik tablicy tymczasowej
    tab = new int[size];
    tab = temp;
}
