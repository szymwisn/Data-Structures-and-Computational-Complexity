#include "Heap.h"
#include <cstdlib>
#include <fstream>

const int randomVal = 10000;

Heap::Heap() {
    size = 0;
    max_size = 100;
    arr = new int[max_size];
}

int Heap::loadFromFile(string FileName) {
    return 0;
}

bool Heap::IsValueInHeap(int value) {
    return false;
}

void Heap::addValue(int value) {

}

void Heap::deleteFromHeap(int value) {

}

void Heap::display() {

}

void Heap::generateHeap(int size) {

}

void Heap::clearHeap() {

}

void Heap::swap() {

}

void Heap::heapify() {

}

int Heap::getParent(int childIndex) {
    return arr[getParentIndex(childIndex)];
}

int Heap::getLeft(int parentIndex) {
    return arr[getLeftIndex(parentIndex)];
}

int Heap::getRight(int parentIndex) {
    return arr[getRightIndex(parentIndex)];
}

int Heap::getParentIndex(int childIndex) {
    return (childIndex - 1) / 2;
}

int Heap::getLeftIndex(int parentIndex) {
    return parentIndex * 2 + 1;
}

int Heap::getRightIndex(int parentIndex) {
    return parentIndex * 2 + 2;
}


