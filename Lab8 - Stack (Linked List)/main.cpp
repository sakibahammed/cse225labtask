

#include <iostream>
#include <string>
#include "stacktype.cpp"
using namespace std;

int priority(char ch) {                          
    int value = 0;
    if (ch == '+') value = 1;
    else if (ch == '-') value = 2;
    else if (ch == '*') value = 3;
    else if (ch == '/') value = 4;

    return value;
}

int main() {
    string input, postfix;
    cin >> input;                              


    StackType<char> st;
    for (char i: input) {
        if (i == ' ')                  
            continue;

        if (isdigit(i))                     
            postfix += i;

        else {
            if (i == '(' || i == ')') {
                if (i == '(')                   
                    st.Push(i);

                else {                           
                    while (!st.IsEmpty() && st.Top() != '(') {
                        postfix = postfix + " " + st.Top();
                        st.Pop();
                    }

                    if (st.IsEmpty()) {         
                        cout << "Invalid input" << endl;
                        return 0;
                    }
                    st.Pop();                 
                continue;
            }

            
            while (!st.IsEmpty() && st.Top() != '(' && priority(st.Top()) > priority(i)) {
                postfix = postfix + " " + st.Top();
                st.Pop();
            }
            postfix += " ";
            st.Push(i);                          
        }
    }

    while (!st.IsEmpty()) {                   
        if (st.Top() == '(') {
            cout << "Invalid input" << endl;
            return 0;
        }
        postfix = postfix + " " + st.Top();
        st.Pop();
    }


    
    StackType<double> result;
    string value;

    for (int i = 0; i < postfix.length(); i++) {

       
        if (!isdigit(postfix[i]) && postfix[i] != ' ') {

            double value2 = result.Top();
            result.Pop();

            if (result.IsEmpty()) {
                cout << "Invalid input" << endl;
                return 0;
            }
            double value1 = result.Top();
            result.Pop();

          
            if (postfix[i] == '+')
                result.Push(value1 + value2);
            else if (postfix[i] == '-')
                result.Push(value1 - value2);
            else if (postfix[i] == '*')
                result.Push(value1 * value2);
            else if (postfix[i] == '/')
                result.Push(value1 / value2);
            i++;
        }

        else if (isdigit(postfix[i])) {      
            value += postfix[i];
        }

        else if (postfix[i] == ' ') {           
            char *ptr;

            
            if (!value.empty())
                result.Push(strtod(value.c_str(), &ptr));
            value = "";
        }
    }

    cout << result.Top() << endl;

    return 0;
}
