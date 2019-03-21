#ifndef INC_241269_TEST_H
#define INC_241269_TEST_H

#include<string>
#include<iostream>
#include <chrono>
#include "Table.h"
#include "List.h"
#include "Heap.h"

class Test {
public:
    void displayMenu(string info);
    void displayMenuHeap(string info);
    void menu_table();
    void menu_list();
    void menu_heap();
};


#endif
