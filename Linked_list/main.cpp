#include <iostream>

using namespace std;

#include "MyNode/MyNode.tpp"
#include "MyLinkedList/MyLinkedList.tpp"



int main() {

//    MyNode<string> node{};
    int arr[] = {1, 2, 3, 4, 5};
    MyLinkedList<int> linkedList{arr, 5};
//    MyLinkedList<int> list {arr, 3};

    linkedList.ReversePrintList();

    linkedList.PrintList();
    linkedList.InsertAt(24, 5);
    linkedList.InsertAt(25, 6);
    linkedList.PrintList();
    linkedList.ReversePrintList();
    int num = linkedList.FindMiddle();
    cout << num << endl;
//    linkedList.DeleteAt(5);
//    linkedList.PrintList();
//    linkedList.ReversePrintList();
    return 0;
}
