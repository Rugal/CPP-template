#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <cassert>

template <typename T>
class Node {
public:
    T data;
    Node<T>* prev = NULL;
    Node<T>* next = NULL;
    Node() {}

    Node(const T& d): data(d) {}

    Node(const T& d, Node<T>* p, Node<T>* n): data(d), prev(p), next(n) {}

    ~Node() {
        this->prev = this->next = NULL;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    unsigned int size;

    bool isValidIndex(const int& index) {
        return 0 <= index && index < this->size;
    }

    Node<T>* getNode(const int&);
public:
    LinkedList(): size(0) {}

    ~LinkedList();

    unsigned int getSize() {
        return this->size;
    }

    bool isEmpty() {
        return 0 == this->size;
    }

    void add(const T&, const int&);

    void addTail(const T&);

    void addHead(const T&);

    void remove(const int&);

    void removeHead();

    void removeTail();

    T get(const int&);
};

template <typename T>
void LinkedList<T>::addTail(const T& data) {
    Node<T>* n = new Node<T>(data);
    if (this->isEmpty()) {
        this->head = this->tail = n;
    } else {
        n->prev = this->tail;
        this->tail->next = n;
        this->tail = n;
    }
    this->size++;
}

template <typename T>
void LinkedList<T>::addHead(const T& data) {
    Node<T>* n = new Node<T>(data);
    if (this->isEmpty()) {
        this->head = this->tail = n;
    } else {
        this->head->prev = n;
        n->next = this->head;
        this->head = n;
    }
    this->size++;
}

template <typename T>
void LinkedList<T>::add(const T& data, const int& index) {
    if (this->isEmpty() || 0 == index) {
        this->addHead(data);
        return;
    }
    Node<T>* origin = this->getNode(index);
    Node<T>* n = new Node<T>(data);
    n->next = origin;
    n->prev = origin->prev;
    origin->prev->next = n;
    origin->prev = n;
    this->size++;
}

template <typename T>
void LinkedList<T>::removeHead() {
    if (this->isEmpty())
        return;
    if (1 == this->size) {
        delete this->head;
        this->head = this->tail = NULL;
    } else {
        Node<T>* temp = this->head;
        this->head = temp->next;
        this->head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    this->size--;
}

template <typename T>
void LinkedList<T>::removeTail() {
    if (this->isEmpty())
        return;
    if (1 == this->size) {
        delete this->head;
        this->head = this->tail = NULL;
    } else {
        Node<T>* temp = this->tail;
        this->tail = temp->prev;
        this->tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    this->size--;
}

template <typename T>
void LinkedList<T>::remove(const int& index) {
    if (0 == index) {
        this->removeHead();
        return;
    }
    if (this->size == index + 1) {
        this->removeTail();
        return;
    }
    Node<T>* origin = this->getNode(index);
    origin->prev->next = origin->next;
    origin->next->prev = origin->prev;
    delete origin;
    this->size--;
}

template <typename T>
Node<T>* LinkedList<T>::getNode(const int& index) {
    assert(isValidIndex(index));
    Node<T>* n = this->head;
    for (int count = 0; n != NULL && count < index; n = n->next, count++);
    assert(n != NULL);
    return n;
}

template <typename T>
T LinkedList<T>::get(const int& index) {
    return this->getNode(index)->data;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(!this->isEmpty()) {
        this->removeHead();
    }
    this->head = this->tail = NULL;
}

#endif /* LINKEDLIST_H */
