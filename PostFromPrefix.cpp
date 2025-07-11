#include<iostream></
#include<stack>
#include<cctype>
using namespace std;
int main(){
      char myArray[] = {'A','+','(','B','*','C','-','(','D','/','E','^','F',')','*','G',')','*','H'};
      stack<char>myStack;
      string postfix="";
      int size=sizeof(myArray)/sizeof(myArray[0]);
      for(int i=0;i<size;i++){
        char ch=myArray[i];
        if(isalpha(ch)){
            postfix=postfix+ch;
        }
        else if(ch=='('){
            myStack.push(ch);
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

                bool operatorEqualOrGreather={
                    (ch=='+' || ch=='-') && (top=='+' || top=='-' || top=='*' || top=='/') || 
                    (ch=='*' || ch=='/') && (top=='*' || top=='/' || top=='^') ||
                    (ch=='^') && (top=='^')
                };
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

      while(!myStack.empty()){
        postfix=postfix+myStack.top();
        myStack.pop();
      }
cout<<postfix;
}