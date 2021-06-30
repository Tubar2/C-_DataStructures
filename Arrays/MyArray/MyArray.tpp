//
// Created by Ricardo Santos on 30/06/21.
//

#pragma once

#include <iostream>
#include "MyArray.hpp"


// MARK: - Methods
    // RESIZE
template<class T>
void MyArray<T>::resize() {
    Capacity *= 2;
    T * newArr = new T[Capacity];
    for (int i = 0; i < Size; ++i) {
        newArr[i] = Arr[i];
    }
    delete [] Arr;
    Arr = newArr;
}

    // APPEND
template<class T>
void MyArray<T>::Append(T el) {
    // Check for max size
    if (Size >= Capacity){
        resize();
    }
    Arr[Size] = el;
    Size++;
}

    // INSERT
template<class T>
bool MyArray<T>::Insert(T el, int idx) {
        // Check for max size
    if (Size >= Capacity){
        resize();
    }
    if (idx < 0 || idx > Size){
        return false;
    }

    for (int i = Size; i > idx; --i) {
        Arr[i] = Arr[i-1];
    }
    Arr[idx] = el;
    Size++;

    return true;
}

    // LEN
template<class T>
int MyArray<T>::Len() {
    return Size;
}

    // DELETE
template<class T>
T MyArray<T>::Delete(int idx) {
    if (idx < 0 || idx >= Size){
        return 0;
    }
    T el = Arr[idx];
    for (int i = idx; i < Size; ++i) {
        Arr[i] = Arr[i+1];
    }
    Size--;
    return el;
}

    // FIND
template<class T>
int MyArray<T>::Find(T key) {
    for (int i = 0; i < Size; ++i) {
        if (key == Arr[i]) return i;
    }
    return -1;
}

    // INVERSE
template<class T>
void MyArray<T>::Reverse() {
    T temp;
    int i,j;
    for (i = 0, j=Size-1; i<j ; i++, j--) {
        temp = Arr[i];
        Arr[i] = Arr[j];
        Arr[j] = temp;
    }

}

// MARK: - Operator Overload
    // []
template<class T>
T &MyArray<T>::operator[](int idx) {
    return Arr[idx];
}


// MARK: - Constructors
    // DEFAULT
template<class T>
MyArray<T>::MyArray() {
    Arr = new T[Capacity];
}

    // (CAPACITY, DEFAULT)
template<class T>
MyArray<T>::MyArray(int capacity, T def):Capacity(capacity), Size(capacity) {
    Arr = new T[Capacity];
    for (int i = 0; i < Capacity; ++i) {
        Arr[i] = def;
    }
}



