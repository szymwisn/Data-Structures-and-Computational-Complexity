#include "Heap.h"

const int randomVal = 10000;


Heap::Heap() {
    size = 0;
    max_size = 30000;
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

        // wyczyszczenie danych
        clearHeap();

        // wczytywanie kolejnych wersow z pliku
        while(getline(file, line)) {
            addValue(stoi(line));
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }

    return 0;
}


bool Heap::IsValueInHeap(int value) {
    // iteruje po tablicy i sprawdza czy element tablicy jest rowny podanej wartosci
    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            return true;
        }
    }

    return false;
}


void Heap::swap(int indexOfSmaller, int indexOfBigger) {
    int temp = arr[indexOfSmaller];

    arr[indexOfSmaller] = arr[indexOfBigger];
    arr[indexOfBigger] = temp;
}


void Heap::heapifyUp(int index) {
    int parentIndex = getParentIndex(index);

    while(arr[index] > arr[parentIndex]) {
        // zamiana elementow miejscami
        swap(index, parentIndex);

        // rekurencyjne wywolanie funkcji dla kolejnych elementow, zaczynajac od indexu rodzica
        index = parentIndex;
        heapifyUp(index);
    }
}


void Heap::heapifyDown(int index) {
    // znalezienie indexow lewego i prawego potomka danego indexu
    int leftChildIndex = getLeftChildIndex(index);
    int rightChildIndex = getRightChildIndex(index);

    int indexOfMax;

    // porownanie lewego dziecka z rodzicem
    if(leftChildIndex <= size && arr[leftChildIndex] > arr[index]) {
        indexOfMax = leftChildIndex;
    } else {
        indexOfMax = index;
    }

    // porownanie prawego dziecka z najwiekszym elementem w danym obrebie
    if(rightChildIndex <= size && arr[rightChildIndex] > arr[indexOfMax]) {
        indexOfMax = rightChildIndex;
    }

    if (indexOfMax != index) {
        // zamiana miejscami - przesuniecie wiekszego elementu w gore drzewa
        swap(index, indexOfMax);

        // rekurencja dla reszty drzewa
        heapifyDown(indexOfMax);
    }
}


void Heap::addValue(int value) {
    if(size < max_size) {
        size++;

        int index = size - 1;
        arr[index] = value;

        // przywrocenie wlasnosci kopca
        heapifyUp(index);
    } else {
        cout << endl << "W tym kopcu nie moze byc wiecej elementow niz " << max_size << "." << endl;
    }
}


void Heap::deleteFromHeap(int value) {
    if(size > 0) {
        if(IsValueInHeap(value)) {
            int position = 0;

            // znalezienie pozycji, ktora chcemy usunac
            while(arr[position] != value) {
                position++;
            }

            // przesuniecie ostatniego elementu na zadana pozycje
            arr[position] = arr[size - 1];

            // zmniejszenie rozmiaru tablicy
            size--;

            // przywrocenie wlasnosci kopca
            heapifyDown(position);

//            cout << endl << "Usunieto wartosc - " << value << endl;
        } else {
//            cout << endl << "W tym kopcu nie ma podanego elementu! - " << value << endl;
        }
    } else {
        cout << endl << "W kopcu nie ma zadnych elementow." << endl;
    }
}


void Heap::display() {
    if (size == 0) {
        cout << endl <<"Brak elementow do wyswietlenia." << endl;
    } else {
        cout << "\nInterpretacja w formie drzewa (wyswietla sie tylko pierwsze 31 elementow): " << endl;

        cout << setw(49) << arr[0] << endl << endl;
        for (int i = 1; i < 3; i++) {
            if (size > i) {
                cout << setw(33);
                if (arr[i] != 0)
                    cout << arr[i];
                else
                    cout << 'x';
            }
        }
        cout << endl << endl;
        for (int i = 3; i < 7; i++) {
            if (size > i) {
                cout << setw(20);
                if (arr[i] != 0)
                    cout << arr[i];
                else
                    cout << 'x';
            }
        }
        cout << endl << endl;
        for (int i = 7; i < 15; i++) {
            if (size > i) {
                cout << setw(11);
                if (arr[i] != 0)
                    cout << arr[i];
                else
                    cout << 'x';;
            }
        }

        cout << endl << endl;
        for (int i = 15; i < 31; i++) {
            if (size > i) {
                cout << setw(6);
                if (arr[i] != 0)
                    cout << arr[i];
                else
                    cout << 'x';;
            }
        }

        cout << endl << endl;

        cout << "Iterpretacja w formie tablicy (wyswietlaja sie wszystkie elementy): " << endl;
        for(int i = 0; i < size; i++) {
            cout << "[" << i << "] " << arr[i] << " ";
        }

        cout << endl;
    }
}


void Heap::generateHeap(int size) {
    // wyczyszczenie kopca
    clearHeap();

    // utworzenie n = size elementow o losowych wartosci
    for(int i = 0; i < size; i ++) {
        addValue(rand() % randomVal);
    }
}


void Heap::clearHeap() {
    size = 0;
    arr = new int[max_size];
}


int Heap::getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

int Heap::getLeftChildIndex(int parentIndex) { return parentIndex * 2 + 1; }

int Heap::getRightChildIndex(int parentIndex) { return parentIndex * 2 + 2; }


