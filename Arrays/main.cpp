#include "MyArray/MyArray.hpp"


using namespace std;

void PrintArray(MyArray<int>& mArr) {
    for (int i = 0; i < mArr.Len(); ++i) {
        std::cout << mArr[i] << " ";
    }
    cout << endl << "done printing" << endl;
}

int main() {
    MyArray<int> mArr;

    for (int i = 0; i < 5; ++i) {
        mArr.Append(i);
    }
//    mArr.Insert(14, 0);

    cout << mArr.Find(12) << "\n";

    mArr.Reverse();
    PrintArray(mArr);


    return 0;
}
