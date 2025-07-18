#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
int main(){
    cout<<"Please take input for array Size: ";
    int arraySize;
    cin>>arraySize;
    char myArray[arraySize];
    cout<<"pLease take array element for myArray: ";
    for(int i=0;i<arraySize;i++){
        cin>>myArray[i];
    }

    stack<char>myStack;
    string postfix="";
    for(int i=0;i<arraySize;i++){
        char ch=myArray[i];
        if(isalpha(ch)){
            postfix+=ch;
        }
        else if(ch=='('){
            myStack.push('(');
        }
        else if(ch==')'){
            while(!myStack.empty() && myStack.top()!='('){
                postfix+=ch;
                myStack.pop();
            }
            if(!myStack.empty()){
                myStack.pop();
            }
        }
        else{
            while(!myStack.empty()){
                char top=myStack.top();

                bool operatorEqualOrGreather=
                (ch=='+' || ch=='-') || (top=='+' || top=='-' || top=='*' || top=='/') ||
                (ch=='*' || ch=='/') || (top=='*' || top=='/' || top=='^') ||
                ( ch=='^') || (top=='^');

                if(operatorEqualOrGreather){
                    postfix+=top;
                    myStack.pop();
                }
                else{
                    break;
                }
             }

             
            myStack.push(ch);
        }
    }

    while(!myStack.empty()){
        if(myStack.top()!='(' && myStack.top()!=')'){
            postfix+=myStack.top();
            myStack.pop();
        }
    }
    cout<<postfix;
}