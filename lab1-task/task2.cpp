
#include <iostream>
using namespace std;

int main() {

    int row, column;  
    cin >> row >> column; 

    int **ptr = new int *[row];  

    for (int i = 0; i < row; i++) {
        ptr[i] = new int[column];  
    }

    for (int i = 0; i < row; i++) {  
        for (int j = 0; j < column; j++) {
            cin >> ptr[i][j];
        }
    }

    for (int i = 0; i < row; i++) { 
        for (int j = 0; j < column; j++) {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    delete[] ptr; 

    return 0;
}
