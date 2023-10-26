
#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main() {

    int size, input;
    dynarr d(5);     

    cin >> size;     
    d.allocate(size);     
    for (int i = 0; i < size; i++) {     
        cin >> input;
        d.setValue(i, input);
    }

    for (int i = 0; i < size; i++) {   
        cout << d.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
