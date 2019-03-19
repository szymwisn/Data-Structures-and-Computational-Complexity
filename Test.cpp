#include "Test.h"

void Test::displayMenu(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1. Usun na poczatku" << endl;
    cout << "2. Usun na koncu" << endl;
    cout << "3. Usun w losowym miejscu" << endl;
    cout << "4. Dodaj na poczatku" << endl;
    cout << "5. Dodaj na koncu" << endl;
    cout << "6. Dodaj w losowym miejscu" << endl;
    cout << "7. Utworz losowo" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Test::displayMenuHeap(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1. Usun w wybranym miejscu (na potrzeby testu wybrane = losowe)" << endl;
    cout << "2. Dodaj" << endl;
    cout << "3. Utworz losowo" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Test::menu_table() {
    Table myTab;

    char opt;
    string fileName;
    int index, value;
    int sum = 0, average = 0;
    int n = 1;

    do {
        displayMenu("--- TESTOWANIE TABLICY ---");
        cin >> opt;
        cout << endl;

        cout << "Ile razy wykonac test?";
        cin >> n;

        if (opt == '1') {
            //tutaj usuwanie elemenu z tablicy na poczatku

            myTab.generateTable(n);

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.deleteFromTableStart();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '2') {
            //tutaj usuwanie elemenu z tablicy na koncu

            myTab.generateTable(n);

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.deleteFromTableEnd();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if(opt == '3') {
            //tutaj usuwanie elemenu z tablicy w losowym miejscu

            myTab.generateTable(n);

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.deleteFromTableRandom();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '4') {
            //tutaj dodawanie pierwszego elemetu do tablicy

            myTab.generateTable(0);

            cout << " podaj wartosc:";
            cin >> value;

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.addValueStart(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '5') {
            //tutaj dodawanie ostatniego elemetu do tablicy

            myTab.generateTable(0);

            cout << " podaj wartosc:";
            cin >> value;

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.addValueEnd(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '6') {
            //tutaj dodawanie losowego elemetu do tablicy

            myTab.generateTable(0);

            cout << " podaj wartosc:";
            cin >> value;

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.addValueRandom(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '7') {
            //tutaj generowanie  tablicy

            cout << "Podaj ilosc elementow tablicy:";
            cin >> value;

            for( int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.generateTable(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }
    } while (opt != '0');
}

void Test::menu_list() {
    List myList;

    char opt;
    string fileName;
    int index, value;
    int sum = 0, average = 0;
    int n = 1;

    do {
        displayMenu("--- TESTOWANIE LISTY ---");
        cin >> opt;
        cout << endl;

        cout << "Ile razy wykonac test?";
        cin >> n;

        if (opt == '1') {
            //tutaj usuwanie elemenu z listy na poczatku

            myList.generateList(n);

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.deleteFromListStart();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '2') {
            //tutaj usuwanie elemenu na koncu

            myList.generateList(n);

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.deleteFromListEnd();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if(opt == '3') {
            //tutaj usuwanie elemenu w losowym miejscu

            myList.generateList(n);

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.deleteFromListRandom();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '4') {
            //tutaj dodawanie pierwszego elemetu

            myList.clearList();

            cout << " podaj wartosc:";
            cin >> value;

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.addValueStart(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '5') {
            //tutaj dodawanie ostatniego elemetu

            myList.clearList();

            cout << " podaj wartosc:";
            cin >> value;

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.addValueEnd(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '6') {
            //tutaj dodawanie losowego elemetu

            myList.clearList();

            cout << " podaj wartosc:";
            cin >> value;

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.addValueRandom(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '7') {
            //tutaj generowanie listy

            cout << "Podaj ilosc elementow tablicy:";
            cin >> value;

            for( int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.generateList(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }
    } while (opt != '0');
}

void Test::menu_heap() {
    Heap myHeap;

    char opt;
    string fileName;
    int index, value;
    int sum = 0, average = 0;
    int n = 1;

    do {
        displayMenuHeap("--- TESTOWANIE KOPCA ---");
        cin >> opt;
        cout << endl;

        cout << "Ile razy wykonac test?";
        cin >> n;

        if (opt == '1') {
            //tutaj usuwanie elemenu z kopca

            myHeap.generateHeap(n);

            for(int i = 0; i < n; i++) {
                value = rand() % 1000;
                auto beginning = std::chrono::steady_clock::now();
                myHeap.deleteFromHeap(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if (opt == '2') {
            //tutaj dodawanie elementu

            myHeap.clearHeap();

            cout << " podaj wartosc:";
            cin >> value;

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myHeap.addValue(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }

        else if(opt == '3') {
            //tutaj tworzenie kopca z losowymi wartosciami

            cout << "Podaj ilosc elementow kopca:";
            cin >> value;

            myHeap.generateHeap(value);

            for(int i = 0; i < n; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myHeap.generateHeap(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / n;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << n << " razy wykonano operacje)." << endl;
        }
    } while (opt != '0');
}