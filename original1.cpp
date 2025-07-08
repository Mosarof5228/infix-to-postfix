#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
int main(){
 char myArray[] = {'5', '+', '6', '*', '2'};
 int size=sizeof(myArray)/sizeof(myArray[0]);
     stack<char> myStack;
     string postfix="";

     for(int i=0;i<size;i++){
        char ch=myArray[i];
        if(isdigit(ch)){
            postfix=postfix+ch;
        }
        else{
            while(!myStack.empty()){
                char top=myStack.top();

                bool higherOrEqualPrecedency=
                (ch=='+' || ch=='-') && (top=='+' || top=='-' || top=='*' || top=='/') ||
                (ch=='*' || ch=='/') && (top=='*' || top=='/');
                if(higherOrEqualPrecedency){
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


     while(!myStack.empty()){
        postfix+=myStack.top();
        myStack.pop();
     }

cout<<postfix;

}