#ifndef INC_241269_HEAP_H
#define INC_241269_HEAP_H

#include<conio.h>
#include<string>
#include<iostream>

using namespace std;

class Heap {
    int size;
    int max_size;
    int *arr;

public:
    Heap();
    int loadFromFile(string FileName);
    bool IsValueInHeap(int value);
    void addValue(int value);
    void deleteFromHeap(int value);
    void display();
    void generateHeap(int size);
    void clearHeap();
    void swap();
    void heapify();
    int getParent(int childIndex);
    int getLeft(int parentIndex);
    int getRight(int parentIndex);
    int getParentIndex(int childIndex);
    int getLeftIndex(int parentIndex);
    int getRightIndex(int parentIndex);
};


#endif
