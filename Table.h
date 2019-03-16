#ifndef INC_241269_TABLE_H
#define INC_241269_TABLE_H

#include <cstdlib>
#include <fstream>
#include<string>
#include<iostream>

using namespace std;

class Table {
    int *tab;  // wskaźnik na tablice
    int size; // ilość elementów w tablicy
    int *temp; // wskaźnik na tymczasowa tablice

public:
    Table();
    int loadFromFile(string FileName);
    bool IsValueInTable(int value);
    void addValue(int index, int value);
    void addValueStart(int value);
    void addValueEnd(int value);
    void addValueRandom(int value);
    void deleteFromTable(int index);
    void deleteFromTableStart();
    void deleteFromTableEnd();
    void deleteFromTableRandom();
    void display();
    void generateTable(int size);
};

#endif
