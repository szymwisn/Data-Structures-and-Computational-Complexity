#ifndef INC_241269_LIST_H
#define INC_241269_LIST_H

#include<conio.h>
#include<string>
#include<iostream>

using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node *previous;
};

class List {
    Node *head;
    Node *tail;
    int size;

public:
    List();
    int loadFromFile(string FileName);
    bool IsValueInList(int value);
    void addValue(int index, int value);
    void addValueStart(int value);
    void addValueEnd(int value);
    void addValueRandom(int value);
    void deleteFromList(int value);
    void display();
    void generateList(int size);
};


#endif
