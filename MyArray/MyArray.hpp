//
// Created by Ricardo Santos on 30/06/21.
//

#pragma once

template<class T>
class MyArray {
private:
    T *Arr;
    int Capacity = 1;
    int Size = 0;

        // Resizes Arr pointer
    void resize();
public:
    // MARK: - Methods
        // Appends element to end of array
    void Append(T el);
        // Inserts element at given index
    bool Insert(T el, int idx);
        // Returns size of array
    int Len();
        // Deletes array at given index
    T Delete(int idx);
        // Searches for element using linear_search
    int Find(T key);
        // Reverses the array in_place
    void Reverse();

    // MARK: - Operator Overload
    T &operator[](int idx);


    // MARK: - Constructors
    MyArray();
    MyArray(int capacity, T def);

};

#include "MyArray.tpp"

