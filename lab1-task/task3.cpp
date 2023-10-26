

#include <iostream>
using namespace std;

int main() {

    int row, column;   
    cin >> row >> column;  
    int colArray[row];  
    int **ptr = new int *[row];

    for (int i = 0; i < row; i++) {
        cin >> column;   
        ptr[i] = new int[column]; 
        colArray[i] = column; 
    }

    for (int i = 0; i < row; i++) {      
        for (int j = 0; j < colArray[i]; j++) {
            cin >> ptr[i][j];
        }
    }

    for (int i = 0; i < row; i++) {  
        for (int j = 0; j < colArray[i]; j++) {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    delete[] ptr;  

    return 0;
}
