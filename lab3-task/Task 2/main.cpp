

#include <iostream>
#include "complex.cpp"
using namespace std;

int main() {

    Complex c1(5, 2), c2(5, 3);  

    Complex c3 = c1 + c2;         
    c3.Print();

    Complex c4 = c1 * c2;     
    c4.Print();

    cout << (c1 != c2) << endl;  

    return 0;
}
