#include<iostream>
#include<stack>
using namespace std;

int main() {
    int arraySize;
    cout << "Please input array Size: ";
    cin >> arraySize;

    char myArray[arraySize]; // Use char array to store digits and operators
    stack<int> myStack;

    cout << "Please enter your postfix expression one by one (digits/operators): ";
    for (int i = 0; i < arraySize; i++) {
        cin >> myArray[i]; // Input characters like 5 3 + 2 *
    }

    for (int i = 0; i < arraySize; i++) {
        char ch = myArray[i];

        if (isdigit(ch)) {
            myStack.push(ch - '0'); // convert '5' to 5
        } else {
            // Pop two elements for the operation
            int a = myStack.top(); myStack.pop();
            int b = myStack.top(); myStack.pop();

            // Perform the operation
            if (ch == '+') {
                myStack.push(b + a);
            } else if (ch == '-') {
                myStack.push(b - a);
            } else if (ch == '*') {
                myStack.push(b * a);
            } else if (ch == '/') {
                myStack.push(b / a);
            }
        }
    }

    cout << "Result = " << myStack.top() << endl;
    return 0;
}
