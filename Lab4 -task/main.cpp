
#include <iostream>
#include "unsortedtype.cpp"
#include "studentInfo.cpp"

using namespace std;

template<class T>
void Print(UnsortedType<T> u) {   

    int length = u.LengthIs();
    T value;

    for (int i = 0; i < length; i++) {
        u.GetNextItem(value);
        cout << value << " ";
    }
    cout << endl;
}

template<class T>
void Retrieve(UnsortedType<T> u, T value) {  
    bool b;
    u.RetrieveItem(value, b);

    if (b)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;

}

void checkFull(bool b) {         
    if (b)
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;
}

int main() {

    // First Task
    UnsortedType<int> ut;          

    ut.InsertItem(5);
    ut.InsertItem(7);
    ut.InsertItem(6);
    ut.InsertItem(9);

    Print(ut);  

    cout << ut.LengthIs() << endl;   
    ut.InsertItem(1);      
    Print(ut);             

    Retrieve(ut, 4);      
    
    Retrieve(ut, 5);
    Retrieve(ut, 9);
    Retrieve(ut, 10);

    checkFull(ut.IsFull());   

    ut.DeleteItem(5);   

    checkFull(ut.IsFull());   

    ut.DeleteItem(1);            
    Print(ut);                 

    ut.DeleteItem(6);       

    Print(ut); 


    // Second Task
    studentInfo s1(15234, "Jon", 2.6),  
    s2(13732, "Tyrion", 3.9),
            s3(13569, "Sandor", 1.2),
            s4(15467, "Ramsey2", 3.1),
            s5(16285, "Arya", 3.1);

    UnsortedType<studentInfo> students;  
    // objects
    students.InsertItem(s1);
    students.InsertItem(s2);
    students.InsertItem(s3);
    students.InsertItem(s4);
    students.InsertItem(s5);

    studentInfo temp = 15467;   
    students.DeleteItem(temp);   

    temp = 13569;            
    Retrieve(students, temp);           
    cout << temp << endl;    

    // Printing the list
    for (int i = 0; i < students.LengthIs(); i++) {
        students.GetNextItem(temp);
        cout << temp;
    }

    return 0;
}
