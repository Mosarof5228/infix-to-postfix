#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arraySize;
    cout<<"Please input array Size: ";
    cin>>arraySize;

    char myArray[arraySize];
    stack<int>myStack;

    cout<<"please enter your array inputs: ";
    for(int i=0;i<arraySize;i++){
        cin>>myArray[i];
    }

    //every element scanned from array
    for(int i=0;i<arraySize;i++){
        char ch=myArray[i];
        if(isdigit(ch)){
            myStack.push(ch);
        }
        else{
            int a=myStack.top();
            myStack.pop();

            int b=myStack.top();
            myStack.pop();

            if(ch=='+'){
                myStack.push(b+a);
            }
            else if(ch=='-'){
                myStack.push(b-a);
            }
            else if(ch=='*'){
                myStack.push(b*a);
            }
            else if(ch=='/'){
                myStack.push(b/a);
            }

        }
    }
    cout<<myStack.top();

   
}