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
    ifstream file;
    string line;

    file.open(FileName);

    if(file.is_open()) {
        // pobiera pierwszy wers - rozmiar tablicy
        getline(file, line);

        // funkcja stoi konwertuje string do int
        size = stoi(line);

        // tworzy tablice o okreslonym rozmiarze
        arr = new int[size];

        // wczytywanie kolejnych wersow z pliku
        int i = 0;
        while(getline(file, line)) {
            arr[i] = stoi(line);
            i++;
        }
        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }

    //TODO up czy down?
    heapify("down");

    return 0;
}

bool Heap::IsValueInHeap(int value) {
    // iteruje po tablicy i sprawdza czy element tablicy jest rowny podanej wartosci
    for(int i = 0 ; i < size; i++) {
        if(arr[i] == value) {
            return true;
        }
    }

    return false;
}

void Heap::addValue(int value) {
    size++;
    arr[size-1] = value;

    //TODO up czy down?
    heapify("up");
}

void Heap::deleteFromHeap(int value) {
    int position = 0;
    int *temp = new int[size];

    // znalezienie pozycji, ktora chcemy usunac
    while(arr[position] != value) {
        position++;
    }

    // wypelnienie tablicy tymczasowej elementami przed dana pozycja
    for(int i = 0; i < position; i++) {
        temp[i] = arr[i];
    }

    // zmniejszenie rozmiaru tablicy
    size--;

    // wypelnienie tablicy tymczasowej elementami po danej pozycji
    for(int i = position; i < size; i++) {
        temp[i] = arr[i + 1];
    }

    arr = temp;

    //TODO down czy up?
    heapify("down");
}

void Heap::display() {
    cout << "\nInterpretacja w formie drzewa: " << endl;

    cout << endl;

    cout << "Iterpretacja w formie tablicy: " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void Heap::generateHeap(int size) {
    this->size = size;

    for(int i = 0; i < size; i++) {
        arr[i] = rand() % randomVal;
    }

    // TODO up czy down?
    heapify("down");
}

void Heap::clearHeap() {
    // TODO sprawdzic

    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    size = 0;
}

void Heap::swap(int a, int b) {
    int temp = arr[a];

    if(arr[b] > arr[a]) {
        arr[a] = arr[b];
        arr[b] = temp;
    }
}

void Heap::heapify(string direction) {
    if(direction == "up") {

    } else {

    }
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


