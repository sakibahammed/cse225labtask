

#include <iostream>
#include "quetype.cpp"
using namespace std;

void checkEmpty(bool b) {                     
    if (b)
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is not Empty" << endl;
}

void checkFull(bool b) {                       
    if (b)
        cout << "Queue is full" << endl;
    else
        cout << "Queue is not full" << endl;
}

void Print(QueType<int> &queType) {            
    QueType<int> temp;

    while (!queType.IsEmpty()) {
        int value;
        queType.Dequeue(value);
        cout << value << " ";
        temp.Enqueue(value);
    }
    cout << endl;

    while (!temp.IsEmpty()) {
        int value;
        temp.Dequeue(value);
        queType.Enqueue(value);
    }
}

int main() {

    // First Task
    QueType<int> queue(5);                    

    checkEmpty(queue.IsEmpty());             

    queue.Enqueue(5);                         
    queue.Enqueue(7);
    queue.Enqueue(4);
    queue.Enqueue(2);

    checkEmpty(queue.IsEmpty());              

    checkFull(queue.IsFull());                

    queue.Enqueue(6);                        

    Print(queue);                              

    checkFull(queue.IsFull());                

    if (!queue.IsFull())                       
        queue.Enqueue(8);
    else
        cout << "Queue Overflow" << endl;

    int d;                                   
    queue.Dequeue(d);
    queue.Dequeue(d);

    Print(queue);                             

    queue.Dequeue(d);                  
    queue.Dequeue(d);
    queue.Dequeue(d);

    checkEmpty(queue.IsEmpty());        

    if (!queue.IsEmpty())                
        queue.Dequeue(d);
    else
        cout << "Queue Underflow" << endl;


    // Second Task
    QueType<string> binary;                     
    int n;
    string var;
    cin >> n;

    binary.Enqueue("1");                       

    while (n--) {                             
        binary.Dequeue(var);                  
        string s1 = var;
        cout << s1 << endl;

        string s2 = s1;
        binary.Enqueue(s1.append("0"));        
        binary.Enqueue(s2.append("1"));         
    }

    return 0;
}
