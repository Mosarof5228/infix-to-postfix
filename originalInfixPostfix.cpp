#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
int main(){
    cout<<"please take arraysize: ";
    int arraySize;
    cin>>arraySize;

    char myArray[arraySize];
    for(int i=0;i<arraySize;i++){
        cin>>myArray[i];
    }

    int size=sizeof(myArray)/sizeof(myArray[0]);

    stack<char>myStack;
    string postfix="";

    for(int i=0;i<size;i++){
        char ch=myArray[i];
        if(isdigit(ch)){
            postfix=postfix+ch;
        }
        else{
            while(!myStack.empty()){
                char top=myStack.top();

                bool equalOrGreather={
                    (ch=='+' || ch=='-') && (top=='+' || top=='-' || top=='*' || top=='/') ||
                    (ch=='*' || ch=='/') && (top=='*' || top=='/')
                };

                if(equalOrGreather){
                    postfix=postfix+myStack.top();
                    myStack.pop();
                }
                {
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

   

