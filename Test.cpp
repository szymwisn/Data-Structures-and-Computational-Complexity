#include "Test.h"

const int tests = 1000;

void Test::displayMenu(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1. Znajdz" << endl;
    cout << "2. Usun na poczatku" << endl;
    cout << "3. Usun na koncu" << endl;
    cout << "4. Usun w losowym miejscu" << endl;
    cout << "5. Dodaj na poczatku" << endl;
    cout << "6. Dodaj na koncu" << endl;
    cout << "7. Dodaj w losowym miejscu" << endl;
    cout << "8. Utworz losowo" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Test::displayMenuHeap(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1. Znajdz" << endl;
    cout << "2. Usun w wybranym miejscu (na potrzeby testu wybrane = losowe)" << endl;
    cout << "3. Dodaj" << endl;
    cout << "4. Utworz losowo" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Test::menu_table() {
    Table myTab;

    char opt;
    string fileName;
    int index, value;
    int sum = 0, average = 0;
    int elements;

    do {
        displayMenu("--- TESTOWANIE TABLICY ---");
        cin >> opt;
        cout << endl;

        cout << "Jakie ma byc rozmiar struktury?";
        cin >> elements;

        if (opt == '1') {
            //tutaj znajdowanie

            myTab.generateTable(elements);

            for(int i = 0; i < tests; i++) {
                value = rand() % 10000;
                auto beginning = std::chrono::steady_clock::now();
                myTab.IsValueInTable(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        if (opt == '2') {
            //tutaj usuwanie elemenu z tablicy na poczatku

            myTab.generateTable(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.deleteFromTableStart();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '3') {
            //tutaj usuwanie elemenu z tablicy na koncu

            myTab.generateTable(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.deleteFromTableEnd();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if(opt == '4') {
            //tutaj usuwanie elemenu z tablicy w losowym miejscu

            myTab.generateTable(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.deleteFromTableRandom();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '5') {
            //tutaj dodawanie pierwszego elemetu do tablicy

            myTab.generateTable(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.addValueStart(1);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '6') {
            //tutaj dodawanie ostatniego elemetu do tablicy

            myTab.generateTable(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.addValueEnd(1);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '7') {
            //tutaj dodawanie losowego elemetu do tablicy

            myTab.generateTable(elements);


            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.addValueRandom(rand() % 10000);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '8') {
            //tutaj generowanie  tablicy

            for( int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myTab.generateTable(elements);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }
    } while (opt != '0');
}

void Test::menu_list() {
    List myList;

    char opt;
    string fileName;
    int index, value;
    int sum = 0, average = 0;
    int elements;

    do {
        displayMenu("--- TESTOWANIE LISTY ---");
        cin >> opt;
        cout << endl;

        cout << "Jakie ma byc rozmiar struktury?";
        cin >> elements;

        if (opt == '1') {
            //tutaj znajdowanie

            myList.generateList(elements);

            for(int i = 0; i < tests; i++) {
                value = rand() % 10000;
                auto beginning = std::chrono::steady_clock::now();
                myList.IsValueInList(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        if (opt == '2') {
            //tutaj usuwanie elemenu z listy na poczatku

            myList.generateList(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.deleteFromListStart();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '3') {
            //tutaj usuwanie elemenu na koncu

            myList.generateList(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.deleteFromListEnd();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if(opt == '4') {
            //tutaj usuwanie elemenu w losowym miejscu

            myList.generateList(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.deleteFromListRandom();
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '5') {
            //tutaj dodawanie pierwszego elemetu

            myList.generateList(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.addValueStart(1);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '6') {
            //tutaj dodawanie ostatniego elemetu

            myList.generateList(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.addValueEnd(1);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '7') {
            //tutaj dodawanie losowego elemetu

            myList.generateList(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.addValueRandom(1);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '8') {
            //tutaj generowanie listy

            for( int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myList.generateList(elements);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }
    } while (opt != '0');
}

void Test::menu_heap() {
    Heap myHeap;

    char opt;
    string fileName;
    int index, value;
    int sum = 0, average = 0;
    int elements;

    do {
        displayMenuHeap("--- TESTOWANIE KOPCA ---");
        cin >> opt;
        cout << endl;

        cout << "Jakie ma byc rozmiar struktury?";
        cin >> elements;

        if (opt == '1') {
            //tutaj znajdowanie elementu

            myHeap.generateHeap(elements);

            for(int i = 0; i < tests; i++) {
                value = rand() % 10000;
                auto beginning = std::chrono::steady_clock::now();
                myHeap.IsValueInHeap(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        if (opt == '2') {
            //tutaj usuwanie elemenu z kopca

            myHeap.generateHeap(elements);

            for(int i = 0; i < tests; i++) {
                value = rand() % 10000;
                auto beginning = std::chrono::steady_clock::now();
                myHeap.deleteFromHeap(value);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if (opt == '3') {
            //tutaj dodawanie elementu

            myHeap.generateHeap(elements);

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myHeap.addValue(1);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }

        else if(opt == '4') {
            //tutaj tworzenie kopca z losowymi wartosciami

            for(int i = 0; i < tests; i++) {
                auto beginning = std::chrono::steady_clock::now();
                myHeap.generateHeap(elements);
                auto end = std::chrono::steady_clock::now();
                auto time = end - beginning;
                sum += time.count();
            }

            average = sum / tests;
            sum = 0;

            cout << "Pomiar zajal srednio " << average << " ms (" << tests << " razy wykonano operacje dla " << elements << " elementow)." << endl;
        }
    } while (opt != '0');
}