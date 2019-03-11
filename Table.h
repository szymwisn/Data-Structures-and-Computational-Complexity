#ifndef INC_241269_TABLE_H
#define INC_241269_TABLE_H

#include<conio.h>
#include<string>
#include<iostream>

using namespace std;

class Table
{
    int *tab;
    int cnt; //ilość elementów w tablicy

public:
    int loadFromFile(string FileName);
    bool IsValueInTable(int val);
    void addValue(int index, int value);
    void deleteFromTable(int index);
    void display();
    void generateTable(int size);
};

#endif
