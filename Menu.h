#ifndef INC_241269_MENU_H
#define INC_241269_MENU_H

#include<conio.h>
#include<string>
#include<iostream>

using namespace std;

class Menu {
public:
    void displayMenu(string info);
    void menu_table();
    void menu_list();
    void menu_heap();
};

#endif