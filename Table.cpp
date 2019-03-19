#include "Table.h"

const int randomVal = 10000;


Table::Table() {
    tab = new int[0];
    size = 0;
}


int Table::loadFromFile(string FileName) {
    ifstream file;
    string line;

    file.open(FileName);

    if(file.is_open()) {
        // pobiera pierwszy wers - rozmiar tablicy
        getline(file, line);

        // funkcja stoi konwertuje string do int
        size = stoi(line);

        // tworzy tablice o okreslonym rozmiarze
        tab = new int[size];

        // wczytywanie kolejnych wersow z pliku
        int i = 0;
        while(getline(file, line)) {
            tab[i] = stoi(line);
            i++;
        }
        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }

    return 0;
}


bool Table::IsValueInTable(int value) {
    // iteruje po tablicy i sprawdza czy element tablicy jest rowny podanej wartosci
    for(int i = 0 ; i < size; i++) {
        if(tab[i] == value) {
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

    // jesli podany index przekracza rozmiar tablicy, nowy element doda sie na ostatniej pozycji
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


void Table::addValueStart(int value) {
    addValue(0, value);
}


void Table::addValueEnd(int value) {
    addValue(size, value);
}


void Table::addValueRandom(int value) {
    // wylosowanie indexu
    int index = rand() % (size + 1);
    addValue(index, value);
}


void Table::deleteFromTable(int index) {
    if(size > 0) {
        // zmniejszenie rozmiaru tablicy
        size--;

        // utworzenie nowej, tymczasowej tablicy
        temp = new int[size];

        // usuwanie pierwszego elementu - wypelnienie tymczasowej tablicy elementami z indexem 1 do konca
        if(index == 0) {
            // size + 1, bo wczesniej pomniejszono o 1, a tu jeszcze potrzebujemy tego elementu
            for(int i = 1; i < size + 1 ; i++) {
                temp[i - 1] = tab[i];
            }
        }

        // usuwanie ostatniego elementu - wypelnienie tymczasowej tablicy elementami z indexem 0 do size - 2
        if(index == size) {
            for(int i = 0; i < index; i++) {
                temp[i] = tab[i];
            }
        }

        // pozostale przypadki
        if(index > 0 && index < size) {
            // wypelnienie tymczasowej tablicy elementami przed danym indexem
            for(int i = 0; i < index; i++) {
                temp[i] = tab[i];
            }

            // wypelnienie tymczasowej tablicy elementami po danym indexie
            // size + 1, bo wczesniej pomniejszono o 1, a tu jeszcze potrzebujemy tego elementu
            for(int i = index; i < size ; i++) {
                temp[i] = tab[i + 1];
            }
        }

        // wskaznik tablicy wskazuje teraz na nowa tablice
        tab = new int[size];
        tab = temp;
    } else {
        cout << "Brak elementow do usuniecia";
    }
}

void Table::deleteFromTableStart() {
    deleteFromTable(0);
}


void Table::deleteFromTableEnd() {
    deleteFromTable(size - 1);
}


void Table::deleteFromTableRandom() {
    int index;

    if(size > 0) {
        index = rand() % size;
    } else {
        cout << "Brak elementow do usuniecia";
    }

    deleteFromTable(index);
}


void Table::display() {
    cout << endl;

    if(size > 0) {
        for(int i = 0; i < size; i++) {
            cout << "[" << i << "] " << tab[i] <<  "   ";
        }
    } else {
        cout << "W tablicy nie ma zadnych elementow." << endl;
    }

    cout << endl;
}


void Table::generateTable(int size) {
    // ustawienie rozmiaru tablicy
    this->size = size;

    // utworzenie tablicy tymczasowej
    temp = new int[size];

    // wypelnienie tablicy tymczasowej losowymi elementami
    for(int i = 0; i < size; i++) {
        temp[i] = (rand() % randomVal) + 1; // zakres <1, 1000>
    }

    // przypisanie wskaznika tablicy wlasciwej na wskaznik tablicy tymczasowej
    tab = new int[size];
    tab = temp;
}