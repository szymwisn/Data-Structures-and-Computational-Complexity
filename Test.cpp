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

}

void Test::menu_table() {
    Table myTab;

    char opt;
    string fileName;
    int index, value;

    do {
        displayMenu("--- TESTOWANIE TABLICY ---");
        cin >> opt;
        cout << endl;
        if (opt == '1') {
            //tutaj usuwanie elemenu z tablicy na poczatku
            auto beginning = std::chrono::steady_clock::now();
            myTab.deleteFromTableStart();
            auto end = std::chrono::steady_clock::now();
            auto time = end - beginning;
            myTab.display();
            cout << "Pomiar zajal " << time.count() << " ms." << endl;
        }

        else if (opt == '2') {
            //tutaj usuwanie elemenu z tablicy na koncu
            auto beginning = std::chrono::steady_clock::now();
            myTab.deleteFromTableEnd();
            auto end = std::chrono::steady_clock::now();
            auto time = end - beginning;
            myTab.display();
            cout << "Pomiar zajal " << time.count() << " ms." << endl;
        }

        else if(opt == '3') {
            //tutaj usuwanie elemenu z tablicy w losowym miejscu
            auto beginning = std::chrono::steady_clock::now();
            myTab.deleteFromTableRandom();
            auto end = std::chrono::steady_clock::now();
            auto time = end - beginning;
            myTab.display();
            cout << "Pomiar zajal " << time.count() << " ms." << endl;
        }

        else if (opt == '4') {
            //tutaj dodawanie pierwszego elemetu do tablicy
            cout << " podaj wartosc:";
            cin >> value;
            auto beginning = std::chrono::steady_clock::now();
            myTab.addValueStart(value);
            auto end = std::chrono::steady_clock::now();
            auto time = end - beginning;
            myTab.display();
            cout << "Pomiar zajal " << time.count() << " ms." << endl;
        }

        else if (opt == '5') {
            //tutaj dodawanie ostatniego elemetu do tablicy
            cout << " podaj wartosc:";
            cin >> value;
            auto beginning = std::chrono::steady_clock::now();
            myTab.addValueEnd(value);
            auto end = std::chrono::steady_clock::now();
            auto time = end - beginning;
            myTab.display();
            cout << "Pomiar zajal " << time.count() << " ms." << endl;
        }

        else if (opt == '6') {
            //tutaj dodawanie losowego elemetu do tablicy
            cout << " podaj wartosc:";
            cin >> value;
            auto beginning = std::chrono::steady_clock::now();
            myTab.addValueRandom(value);
            auto end = std::chrono::steady_clock::now();
            auto time = end - beginning;
            myTab.display();
            cout << "Pomiar zajal " << time.count() << " ms." << endl;
        }

        else if (opt == '7') {
            //tutaj generowanie  tablicy
            cout << "Podaj ilosc elementow tablicy:";
            cin >> value;
            auto beginning = std::chrono::steady_clock::now();
            myTab.generateTable(value);
            auto end = std::chrono::steady_clock::now();
            auto time = end - beginning;
            myTab.display();
            cout << "Pomiar zajal " << time.count() << " ms." << endl;
        }
    } while (opt != '0');
}

void Test::menu_list() {

}

void Test::menu_heap() {

}