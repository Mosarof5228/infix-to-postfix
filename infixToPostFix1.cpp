#include<iostream>
#include<stack>
using namespace std;
int main(){
       char myArray[]={'5','6','2','+','*','8','4','/','-'};
       stack<int>myStack;
       for(int i=0;i<9;i++){
        char ch=myArray[i];
        if(isdigit(ch)){
            myStack.push(ch-'0');
        }
        else{
            int a=myStack.top();
            myStack.pop();
            int b=myStack.top();
            myStack.pop();

            if(ch=='+'){
                myStack.push(b+a);
            }
            if(ch=='-'){
                myStack.push(b-a);
            }
            if(ch=='*'){
                myStack.push(b*a);
            }
            if(ch=='/'){
                myStack.push(b/a);
            }
        }
       }
       cout<<myStack.top();
}