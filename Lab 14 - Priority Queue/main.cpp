

#include <iostream>
#include "pqtype.cpp"
using namespace std;

void checkEmpty(bool b) {                        
    if (b)
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;
}

int main() {

    PQType<int> pq(15);                         

    checkEmpty(pq.IsEmpty());                    
    for (int i = 0; i < 10; i++) {               
        int temp;
        cin >> temp;
        pq.Enqueue(temp);
    }
    checkEmpty(pq.IsEmpty());                    

    int value;
    pq.Dequeue(value);                         
    cout << value << endl;

    pq.Dequeue(value);                          
    cout << value << endl;


    // Second Problem
    int numberOfBags, minutes, total = 0;
    cin >> numberOfBags >> minutes;

    PQType<int> bagsOfCandies(numberOfBags);

    for (int i = 0; i < numberOfBags; i++) {
        int temp;
        cin >> temp;
        bagsOfCandies.Enqueue(temp);
    }

    for (int i = minutes; i > 0; i--) {
        bagsOfCandies.Dequeue(value);
        total += value;
        bagsOfCandies.Enqueue(value / 2);
    }

    cout << total << endl;

    return 0;
}
