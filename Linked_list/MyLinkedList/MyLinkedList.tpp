//
// Created by Ricardo Santos on 30/06/21.
//

#ifndef LINKED_LIST_MYLINKEDLIST_TPP
#define LINKED_LIST_MYLINKEDLIST_TPP

#include "../MyNode/MyNode.tpp"

#include <iostream>

//
// MARK: - LINKED_LIST Class Header
//
template<typename T>
class MyLinkedList {
private:
    MyNode<T> * head;
    MyNode<T> * last;
    unsigned int size = 0;

public:
    // MARK: - Methods
    void PrintList();
    void ReversePrintList();
    inline unsigned int getSize(){ return size;}
    void InsertAt(T el, int idx);
    T DeleteAt(int idx);

    // MARK: - Algorithms
    T FindMiddle();

    // MARK: - Constructor
    MyLinkedList():head(NULL), last(NULL) {}
    MyLinkedList(T arr[], int N);

    // MARK: - Destructor
     ~MyLinkedList();
};

template<typename T>
MyLinkedList<T>::MyLinkedList(T arr[], int N) {
    head = new MyNode<T>{arr[0], NULL, NULL};
    last = head;

    for (int i = 1; i < N; ++i) {
        auto * temp = new MyNode<T>{arr[i], NULL, last};
        last->next = temp;

        last = temp;
    }
    size = N;
}

template<typename T>
void MyLinkedList<T>::PrintList() {
    MyNode<T> * cursor = head;

    while (cursor) {
        std::cout << cursor->data << " ";
        cursor = cursor->next;
    }
    std::cout << std::endl;
}

template<typename T>
void MyLinkedList<T>::ReversePrintList() {
    MyNode<T> * cursor = last;

    while (cursor) {
        std::cout << cursor->data << " ";
        cursor = cursor->prev;
    }
    std::cout << std::endl;
}

template<typename T>
void MyLinkedList<T>::InsertAt(T el, int idx) {
    if (idx < 0 || idx > size){
        return;
    }
    auto * newNode = new MyNode<T>{el, NULL, NULL};
    MyNode<T> * cursor = head;

    // Insert at beggining
    if (idx == 0){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        // Go to index
        for (int i = 0; i < idx-1; ++i) {
            cursor = cursor->next;
        }
        newNode->next = cursor->next;
        cursor->next = newNode;
        newNode->prev = cursor;
        if(newNode->next) {
            newNode->next->prev = newNode;
        } else {
            last = newNode;
        }
    }
    size++;
}

template<typename T>
T MyLinkedList<T>::DeleteAt(int idx) {
    if (idx < 0 || idx >= size) {
        return NULL;
    }
    MyNode<T> * cursor = head;
    T data;
    if (idx == 0) {
        head = head->next;
        cursor->next->prev = NULL;
    } else {
        MyNode<T> * prev;
        for (int i = 0; i < idx; ++i) {
            prev = cursor;
            cursor = cursor->next;
        }
        prev->next = cursor->next;
        if (cursor->next) {
            cursor->next->prev = prev;
        } else {
            last = prev;
        }
    }

    data = cursor->data;
    delete cursor;
    size--;

    return data;
}

template<typename T>
MyLinkedList<T>::~MyLinkedList() {
    MyNode<T> * cursor = head;
    while (cursor) {
        head = head->next;
        delete cursor;
        cursor = head;
    }
}

template<typename T>
T MyLinkedList<T>::FindMiddle() {
    if (size <= 0){
        return NULL;
    }
    MyNode<T> * fCur = head;
    MyNode<T> * sCur = head;
    while (sCur) {
        sCur = sCur->next;
        if (sCur) {
            sCur = sCur->next;
            fCur = fCur->next;
        }
    }
    return fCur->data;
}


#endif //LINKED_LIST_MYLINKEDLIST_TPP
