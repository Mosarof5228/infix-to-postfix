#include<iostream>
#include<stack>
#include<cctype> // for isdigit()
using namespace std;

int main() {
    // Infix expression: 5 + 6 * 2
    // You can change this array to test other expressions
    char expression[] = {'5', '+', '6', '*', '2'};
    int size = sizeof(expression) / sizeof(expression[0]);

    stack<char> operatorStack; // stack to hold operators
    string postfix = "";       // to store the final postfix result

    // Loop through each character of the expression
    for(int i = 0; i < size; i++) {
        char ch = expression[i];

        // If the character is a digit (operand), add it to postfix
        if(isdigit(ch)) {
            postfix += ch;
        }
        // If the character is an operator (+, -, *, /)
        else {
            // Check operator precedence and pop from stack if needed
            while(!operatorStack.empty()) {
                char top = operatorStack.top();

                // Compare precedence: * and / > + and -
                bool higherOrEqualPrecedence =
                    (ch == '+' || ch == '-') && (top == '*' || top == '/' || top == '+' || top == '-') ||
                    (ch == '*' || ch == '/') && (top == '*' || top == '/');

                if(higherOrEqualPrecedence) {
                    postfix += top;
                    operatorStack.pop();
                } else {
                    break;
                }
            }

            // Push the current operator to the stack
            operatorStack.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while(!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    // Show the final postfix expression
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
