

#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main() {

    int row, col, input;
    dynarr d(5, 5);     

    cin >> row >> col; 
    d.allocate(row, col);  

    for (int i = 0; i < row; i++) {   
        for (int j = 0; j < col; j++) {
            cin >> input;
            d.setValue(i, j, input);
        }
    }
    for (int i = 0; i < row; i++) {     
        for (int j = 0; j < col; j++) {
            cout << d.getValue(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
