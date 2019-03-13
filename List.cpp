#include "List.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

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

    file.open(FileName);

    if(file.is_open()) {
        // pobiera pierwszy wers - ilosc elementow
        getline(file, line);
        // funkcja stoi konwertuje string do int
        size = stoi(line);

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

}


void List::addValueStart(int value) {
    // tworzy node o danej wartosci bez zadnych powiazan
    Node *node = new Node(value); // previous i next sa NULL

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


void List::addValueEnd(int value) {
    // tworzy node o danej wartosci bez zadnych powiazan
    Node *node = new Node(value); // previous i next sa NULL

    // if - lista pusta
    // else - lista ma juz jakis element
    if(head == NULL) {
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


void List::addValueRandom(int value) {

}


void List::deleteFromList(int value) {

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

    //TODO to tylko do testow, potem usunac
    cout << endl << "h: " <<  head->value << endl << "t: " << tail->value;

}


void List::generateList(int size) {
    // dzieki temu rand nie bedzie generowalo zawsze tej samej sekwencji liczb
    srand(time(NULL));

    // licznik potrzebny do petli
    int counter = 0;

    while(counter < size) {
        addValueStart(rand() % 100);
        counter++;
    }
}
