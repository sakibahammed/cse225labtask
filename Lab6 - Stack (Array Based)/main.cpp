
#include <iostream>
#include "stacktype.cpp"
using namespace std;

void checkEmpty(bool b) {                     
    if (b)
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;
}

void checkFull(bool b) {                       
    if (b)
        cout << "Stack is Full" << endl;
    else
        cout << "Stack is not Full" << endl;
}

void Print(StackType<int> st) {            
    StackType<int> temp;

    while (!st.IsEmpty()) {
        temp.Push(st.Top());
        st.Pop();
    }

    while (!temp.IsEmpty()) {
        st.Push(temp.Top());
        cout << temp.Top() << " ";
        temp.Pop();
    }
    cout << endl;
}

int main() {

    // First Task
    StackType<int> st;     

    checkEmpty(st.IsEmpty()); 
    st.Push(5);                               
    st.Push(7);
    st.Push(4);
    st.Push(2);

    checkEmpty(st.IsEmpty());                

    checkFull(st.IsFull());             

    Print(st);                        
    st.Push(3);                       
    Print(st);                         

    checkFull(st.IsFull());                   
    st.Pop();                                
    st.Pop();

    cout << st.Top() << endl;                


    // Second Task
    StackType<char> parentheses;            

    string str;                               
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++) {     

        char array_item = str[i];

        if (array_item == '(')
            parentheses.Push(array_item);

        try {
            if (array_item == ')')
                parentheses.Pop();
        }
        catch (EmptyStack) {
            cout << "Unbalanced" << endl;
            return 0;
        }
    }

    if (parentheses.IsEmpty())
        cout << "Balanced" << endl;
    else
        cout << "Not balanced" << endl;

    return 0;
}
