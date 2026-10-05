#include<iostream>
using namespace std; 

#define MAX 100

class Stack
{
    int stack[MAX];
    int top;
    int capacity;

public:
    Stack(int n)
    {
        capacity=n;
        top=-1;
    }

    void push(int tray)
    {
        if(top==capacity-1)
        {
            cout<<"Error: Stack is full"<<endl; 
            return; 
        }

        top++;
        stack[top]=tray;
        cout<<"Top tray: "<<stack[top]<<endl;
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"Error: Stack is empty"<<endl;
            return; 
        }

        cout<<"Top tray: "<<stack[top]<<endl;
        top--; 
    }
};

int main()
{
    int n;
    cin>>n; 

    Stack s(n);

    int q;
    cin>>q;

    for(int i=0;i<q;i++)
    {
        char operation; 
        cin>>operation; 
        if(operation=='P')
        {
            int tray;
            cin>>tray;
            s.push(tray);
        }
        else if(operation=='T')
        {
            s.pop();
        }
    }
    return 0; 
}