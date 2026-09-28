#include<iostream>
#include<string> 
using namespace std;

struct Node // Represents one browser history page
{
    string page; // Stores the page name
    Node* next; // Points to the previous page

    Node(string p) // Constructor to create a new node
    {
        page=p; // Stores the page name
        next=NULL; // Initially points to no page
    }
};

class Browser // Defines the browser history stack
{
    Node* top; // Points to the current page

public:
    Browser() // Constructor initializes empty history
    {
        top=NULL; // NULL means no page exists
    }

    void visit(string page) // Adds a newly visited page
    {
        Node* newNode=new Node(page); // Creates a new node
        newNode->next=top; // Links it to the previous page
        top=newNode; // Makes the new page the current page
        cout<<"Current page: "<<top->page<<endl; // Prints current page
    }

    void back() // Returns to the previous page
    {
        if(top==NULL) // Checks whether history is empty
        {
            cout<<"Error: No history available"<<endl; // Prints error
            return; // Stops the back operation
        }

        Node* temp=top; // Stores the current page temporarily
        top=top->next; // Moves to the previous page

        if(top==NULL) // Checks whether any page remains
            cout<<"No page open"<<endl; // Prints if history is empty
        else
            cout<<"Current page: "<<top->page<<endl; // Prints current page

        delete temp; // Frees memory of the removed page
    }
};

int main() 
{
    Browser b; // Creates a browser history stack
    int n; // Stores the number of operations
    cin>>n; // Reads the number of operations

    while(n--) // Repeats for all operations
    {
        string operation; // Stores the operation type
        cin>>operation; // Reads the operation

        if(operation=="visit") // Checks for a visit operation
        {
            string page; // Stores the page name
            cin>>page; // Reads the page name
            b.visit(page); // Adds the page to history
        }
        else if(operation=="back") // Checks for a back operation
        {
            b.back(); // Goes to the previous page
        }
    }

    return 0;
}