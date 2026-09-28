#include<iostream>
using namespace std; 

#define MAX 100 //Defines maximum array capacity

class Stack
{
    int stack[MAX]; //Creates an array to store trays
    int top; //Stores the index of the top tray
    int capacity; //Stores the max capacity of the stack

public:
    Stack(int n) //Constructor receives the stack capacity
    {
        capacity=n; //Sets the capacity given by the user
        top=-1; // Stack is empty
    }

    void push(int tray) //add a play to the top
    {
        if(top==capacity-1) //Checks if the stack is full
        {
            cout<<"Error: Stack is full"<<endl; 
            return; 
        }

        top++;
        stack[top]=tray; //Adds the tray at the top
        cout<<"Top tray: "<<stack[top]<<endl;
    }

    void pop() //remove the top tray
    {
        if(top==-1) //stack is empty
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
    int n; //max stack capacity
    cin>>n; 

    Stack s(n); //Creates a stack with capacity n

    int q; //the number of operations
    cin>>q;

    for(int i=0;i<q;i++) //for operations
    {
        char operation; 
        cin>>operation; 
        if(operation=='P')//P=push/add 
        {
            int tray; //Stores the tray number
            cin>>tray;
            s.push(tray); //Adds new tray to the stack
        }
        else if(operation=='T')//T=take
        {
            s.pop(); //Removes the top tray
        }
    }
    return 0; 
}