#include <iostream>
#include <stack>
using namespace std;

int main() {
    int arraySize;
    cout << "Please input array Size: ";
    cin >> arraySize;

    char myArray[arraySize]; // Use char array
    stack<int> myStack;

    cout << "Please enter your postfix expression one by one (e.g., 5 3 + 2 *):\n";
    for (int i = 0; i < arraySize; i++) {
        cin >> myArray[i]; // input one char at a time
    }

    // process postfix expression
    for (int i = 0; i < arraySize; i++) {
        char ch = myArray[i];

        if (isdigit(ch)) {
            // convert char digit to int and push
            myStack.push(ch - '0');
        } else {
            // it's an operator
            if (myStack.size() < 2) {
                cout << "Error: Not enough operands.\n";
                return 1;
            }

            int a = myStack.top(); myStack.pop();
            int b = myStack.top(); myStack.pop();

            if (ch == '+') myStack.push(b + a);
            else if (ch == '-') myStack.push(b - a);
            else if (ch == '*') myStack.push(b * a);
            else if (ch == '/') myStack.push(b / a);
            else {
                cout << "Unknown operator: " << ch << endl;
                return 1;
            }
        }
    }

    // Final result
    if (myStack.size() == 1) {
        cout << "Result = " << myStack.top() << endl;
    } else {
        cout << "Error: Invalid postfix expression.\n";
    }

    return 0;
}

