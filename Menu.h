#ifndef INC_241269_MENU_H
#define INC_241269_MENU_H

#include<string>
#include<iostream>
#include "Table.h"
#include "List.h"
#include "Heap.h"

using namespace std;

class Menu {
public:
    void displayMenu(string info);
    void displayMenuHeap(string info);
    void menu_table();
    void menu_list();
    void menu_heap();
};

#endif