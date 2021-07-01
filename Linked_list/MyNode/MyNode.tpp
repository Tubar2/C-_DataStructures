//
// Created by Ricardo Santos on 30/06/21.
//

#ifndef LINKED_LIST_MYNODE_TPP
#define LINKED_LIST_MYNODE_TPP

//
// MARK: - NODE Class Header
//
template<typename T>
class MyNode {
public:
    T data;
    MyNode<T> * next;
    MyNode<T> * prev;

    MyNode(T data, MyNode<T> *next);
    MyNode(T data, MyNode<T> *next, MyNode<T> *prev);

};

template<typename T>
MyNode<T>::MyNode(T data, MyNode<T> *next)
    :data(data), next(next) {

    }

template<typename T>
MyNode<T>::MyNode(T data, MyNode<T> *next, MyNode<T> *prev)
        :data(data), next(next), prev(prev) {

}

//
// MARK: - Definitions
//




#endif //LINKED_LIST_MYNODE_TPP
