#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
int main(){
    cout<<"please take input for array size: ";
    int arraySize;
    cin>>arraySize;

    
    char myArray[arraySize];
    cout<<"please take input for array element: ";
    for(int i=0;i<arraySize;i++){
        cin>>myArray[i];
    };

    int size=sizeof(myArray)/sizeof(myArray[0]);
    stack<char>myStack;
    string postfix="";
    for(int i=0;i<size; i++){
        char ch=myArray[i];
        if(isalpha(ch)){
            postfix=postfix+ch;

        }
       else if(ch=='('){
            myStack.push('(');
        }
        else if(ch==')'){
            while(!myStack.empty() && myStack.top()!='('){
                postfix=postfix+myStack.top();
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
                    (ch=='+' || ch=='-') && (top=='+' || top=='-' || top=='*' || top=='/') ||
                    (ch=='*' || ch=='/') && (top=='*' || top=='/' || top=='^') ||
                    (ch=='^') && (top=='^');

                

                if(operatorEqualOrGreather){
                    postfix=postfix+top;
                    myStack.pop();
                }
                else{
                    break;
                }
            }

            myStack.push(ch);
        }

    }
    //remaining oprator empty from stack;

    while (!myStack.empty()){
        postfix=postfix+myStack.top();
        myStack.pop();
    }

    cout<<postfix;

}