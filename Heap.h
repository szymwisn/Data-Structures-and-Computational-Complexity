#ifndef INC_241269_HEAP_H
#define INC_241269_HEAP_H

#include<string>
#include<iostream>
#include <cstdlib>
#include <fstream>
#include<iomanip>
#include<cmath>

using namespace std;

class Heap {
    int size;
    int max_size;
    int *arr;

public:
    Heap();
    int loadFromFile(string FileName);
    bool IsValueInHeap(int value);
    void heapifyUp(int index);
    void heapifyDown(int index);
    void addValue(int value);
    void deleteFromHeap(int value);
    void swap(int a, int b);
    void display();
    void generateHeap(int size);
    void clearHeap();
    int getParentIndex(int childIndex);
    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
};


#endif
