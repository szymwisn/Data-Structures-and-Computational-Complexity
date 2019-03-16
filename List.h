#ifndef INC_241269_LIST_H
#define INC_241269_LIST_H

#include<string>
#include<iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node *previous;
    Node(int value);
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
    void deleteFromListStart();
    void deleteFromListEnd();
    void deleteFromListRandom();
    void display();
    void generateList(int size);
    void clearList();
};


#endif
