#include "List.h"
#include <cstdlib>
#include <fstream>

const int randomVal = 10000;
bool decremented = false;

Node::Node(int value) {
    this->value = value;
    this->next = NULL;
    this->previous = NULL;
}

List::List() {
    head = NULL;
    tail = NULL;
    size = 0;
}

int List::loadFromFile(string FileName) {
    ifstream file;
    string line;

    clearList();

    file.open(FileName);

    if(file.is_open()) {
        // pobiera pierwszy wers - ilosc elementow, ale i tak tego nie wykorzystuje w liscie, po prostu chce sie pozbyc pierwszej linii
        getline(file, line);

        // wczytywanie kolejnych wersow z pliku do do listy
        while(getline(file, line)) {
            addValueStart(stoi(line));
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }

    return 0;
}


bool List::IsValueInList(int value) {
    // ustawienie wskaznika na head
    Node *node = head;

    if(head == NULL) {
        cout << "Lista jest pusta" << endl;
    } else {
        // iteracja kolejno od head do konca i porownywanie wartosci kolejnych node
        do {
            if(node->value == value) {
                return true;
            }
            node = node->next;
        } while(node != NULL);
    }

    return false;
}


void List::addValue(int index, int value) {
    // uwtworzenie node o okreslonej wartosci
    Node *node = new Node(value);

    // = = = = = = = = = = = = = = =
    // dodawanie na poczatku
    // = = = = = = = = = = = = = = =
    if(index == 0) {
        // if - lista pusta
        // else - lista ma juz jakis element
        if(head == NULL) {
            head = tail = node;
        } else {
            // dowiazanie node do elementu przed head
            head->previous = node;
            // dowiazanie head do elementu za node
            node->next = head;
            // po tych dwoch operacjach mamy obustronne powiazanie node i head
            // NULL <- node <=> head <=> ... -> NULL

            // head ustawiam na ostatni element listy
            head = node;
        }
    }

    // = = = = = = = = = = = = = = =
    // dodawanie na koncu
    // = = = = = = = = = = = = = = =
    else if(index == size) {
        // if - lista pusta
        // else - lista ma juz jakis element
        if(tail == NULL) {
            tail = head = node;
        } else {
            // dowiazanie node do elementu za tail
            tail->next = node;
            // dowiazanie tail do elementu przed node
            node->previous = tail;
            // po tych dwoch operacjach mamy obustronne powiazanie tail i node
            // NULL <- ... <=> tail <=> node -> NULL

            // tail ustawiam na ostatni element listy
            tail = node;
        }
    }

    // = = = = = = = = = = = = = = =
    // dodawanie w dowolnym miejscu, oprocz poczatku i konca
    // = = = = = = = = = = = = = = =
    else if(index > 0 && index < size) {
        // temp1 - element przed node, temp2 - element za node
        Node *prevNode, *nextNode;

        // counter sluzy do iteracji w petli while
        int counter = 0;

        // przesuwanie od head do wwybranego miejsca
        prevNode = head;
        while (counter < index - 1) {
            prevNode = prevNode->next;
            counter++;
        }

        // zdefiniowanie czym jest nextNode - w tej chwili jest to element bezposrednio po prevNode
        nextNode = prevNode->next;

        // powiazanie node z nextNode
        node->next = nextNode;
        nextNode->previous = node;

        // powiazanie node z prevNode
        prevNode->next = node;
        node->previous = prevNode;

        // ostateczny efekt:  NULL <= ... <=> prevNode <=> node <=> nextNode <=> ... => NULL
    }

    // zwiekszenie rozmiaru listy
    size++;
}


void List::addValueStart(int value) {
    addValue(0, value);
}


void List::addValueEnd(int value) {
    addValue(size, value);
}


void List::addValueRandom(int value) {
    // jesli lista jest pusta to dodajemy element na pierwszej pozycji
    // bez uwzglednienia tego index nie moglby byc wylosowany gdyby nie bylo elementow
    // w tablicy, bo byloby rand() % 0
    if(size == 0) {
        addValue(0, value);
    } else {
        // wylosowanie indexu
        int index = rand() % size;
        addValue(index, value);
    }
}


void List::deleteFromList(int value) {
    Node *node;
    bool done = false;

    // TODO jak zostaje pojedynczy elemento to nie daje sie usunac
    // TODO nie usuwa ostatniego element jak jest sporo elementow

    // zmniejszenie rozmiaru tablicy i poinformowanie funkcji, ktore moga pozniej wystapic -
    // deleteFromListStart i deleteFromListEnd, ze rozmiar zostal juz pomniejszony i nie
    // trzeba robic tego drugi raz
    size--;
    decremented = true;

    do {
        // wyszukanie elementu do usuniecia
        node = head;

        // jesli node jest pojedynczym elementem to nie mozna isc do nastepnego node
        if (head == tail) {
            continue;
        } else {
            while(node->value != value) {
                node = node->next;
            }
        }

        // usuniecie z poczatku listy
        if(node == head) {
            deleteFromListStart();
        }

        // usuniecie z konca listy
        else if(node == tail) {
            deleteFromListEnd();
        }

        // usuniecie z pozostalych miejsc
        else {
            Node *prevNode, *nextNode;

            // zdefiniowanie prevNode i nextNode
            prevNode = node->previous;
            nextNode = node->next;

            // usuniecie node
            node->previous = NULL;
            node->next = NULL;
            node = NULL;

            // powiazanie prevNode z nextNode
            prevNode->next = nextNode;
            nextNode->previous = prevNode;
        }

        //sprawdzenie czy istnieje jeszcze jakis node o podanej wartosci
        node = head;
        while(node->value != value) {
            if(node->next == NULL) {
                break;
            }
            node = node->next;
        }

        if(node == tail) {
            done = true;
        }
    } while(!done);

    decremented = false;
}

void List::deleteFromListStart() {
    Node *node = head;

    if(!decremented) {
        size--;
    }

    if(node == tail) {
        head = NULL;
        tail = NULL;
    } else {
        node = head->next;
        node->previous = NULL;
        head = node;
    }
}

void List::deleteFromListEnd() {
    Node *node = tail;

    if(!decremented) {
        size--;
    }

    if(node == head) {
        head = NULL;
        tail = NULL;
    } else {
        node = tail->previous;
        node->next = NULL;
        tail = node;
    }
}

void List::deleteFromListRandom() {
    Node *node = head;

    bool found = false;

    // wylosowanie wartosci do usuniecia
    int value = rand() % randomVal;

    while(node->next != NULL) {
        node = node->next;
        if(node->value == value) {
            found = true;
        }
    }

    if(found) {
        deleteFromList(value);
        cout << "Usunieto element o wartosci: " << value << endl;
    } else {
        cout << "Nie znaleziono elementu o wylosowanej wartosci - " << value << "." << endl;
    }
}


void List::display() {
    // utworzenie tymczasowego node wskazujacego na head
    Node *node = head;

    // od przodu do tylu w pierwszej linii
    cout << "head -> tail: ";
    if (head == NULL) {
        cout << "Lista jest pusta" << endl;
    } else {
        do {
            cout << node->value << " ";
            node = node->next;
        } while(node != NULL);
    }

    cout << endl;

    // przestawienie wskaznika na tail
    node = tail;

    // od tylu do przodu w drugiej linii
    cout << "tail -> head: ";
    if (tail == NULL) {
        cout << "Lista jest pusta" << endl;
    } else {
        do {
            cout << node->value << " ";
            node = node->previous;
        } while(node != NULL);
    }
}


void List::generateList(int size) {
    clearList();

    // licznik potrzebny do petli
    int counter = 0;

    while(counter < size) {
        addValueStart(rand() % randomVal);
        counter++;
    }

    this->size = size;
}

void List::clearList() {
    // TODO wyczyscic pozostale elementy listy
    // wyczysc stara liste
    this->head = NULL;
    this->size = 0;
    this->tail = NULL;
}
