

#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main() {

    int input, size = 5;
    dynArr<int> dint(size);  

    for (int i = 0; i < size; i++) { 
        cin >> input;
        dint.setValue(i, input);
    }

    for (int i = 0; i < size; i++) {   
        cout << dint.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
