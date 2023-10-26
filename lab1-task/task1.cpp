
#include <iostream>
using namespace std;

int main() {

    int arraySize; 
    cin >> arraySize;      

    int *ptr = new int[arraySize]; 

    for (int i = 0; i < arraySize; i++) {
        cin >> ptr[i]; 
    }
    for (int i = 0; i < arraySize; i++) {
        cout << ptr[i] << " ";   
    }
    cout << endl;

    delete[] ptr;  

    return 0;
}
