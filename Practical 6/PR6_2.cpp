#include<iostream>
#include<string> 
using namespace std;

struct Node
{
    string page;
    Node* next;

    Node(string p)
    {
        page=p;
        next=NULL;
    }
};

class Browser
{
    Node* top;

public:
    Browser()
    {
        top=NULL;
    }

    void visit(string page)
    {
        Node* newNode=new Node(page);
        newNode->next=top;
        top=newNode;
        cout<<"Current page: "<<top->page<<endl;
    }

    void back()
    {
        if(top==NULL)
        {
            cout<<"Error: No history available"<<endl;
            return;
        }

        Node* temp=top;
        top=top->next;

        if(top==NULL)
            cout<<"No page open"<<endl;
        else
            cout<<"Current page: "<<top->page<<endl;

        delete temp;
    }
};

int main() 
{
    Browser b;
    int n;
    cin>>n;

    while(n--)
    {
        string operation;
        cin>>operation;

        if(operation=="visit")
        {
            string page;
            cin>>page;
            b.visit(page);
        }
        else if(operation=="back")
        {
            b.back();
        }
    }
    return 0;
}