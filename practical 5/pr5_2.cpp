#include<iostream>
#include<string>
using namespace std;
struct SNode 
{
    string name;
    SNode* next;
    SNode(string n) 
    {
        name = n;
        next = NULL;
    }
};
class SinglyCircular 
{
    SNode* head;
public:
    SinglyCircular() 
    {
        head = NULL;
    }
    void join(string name, int pos) 
    {
        SNode* newNode = new SNode(name);
            if (head == NULL) 
            {
            head = newNode;
            head->next = head;
            return;
        }
        if (pos == 1) 
        {
            SNode* temp = head;
            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
            return;
        }
        SNode* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
    void leave(int pos) 
    {
        if (head == NULL)
            return;
        if (head->next == head) 
        {
            delete head;
            head = NULL;
            return;
        }
        if (pos == 1) 
        {
            SNode* last = head;
            while (last->next != head)
                last = last->next;

            SNode* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }
        SNode* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        if (temp->next != head) 
        {
            SNode* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
    void display() 
    {
        if (head == NULL) 
        {
            cout << "Circle is empty\n";
            return;
        }
        SNode* temp = head;
        do 
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
struct DNode 
{
    string name;
    DNode* next;
    DNode* prev;

    DNode(string n) 
    {
        name = n;
        next = prev = NULL;
    }
};
class DoublyCircular 
{
    DNode* head;

public:
    DoublyCircular() 
    {
        head = NULL;
    }
    void join(string name, int pos) 
    {
        DNode* newNode = new DNode(name);

        if (head == NULL) 
        {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        if (pos == 1) 
        {
            DNode* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }

        DNode* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void leave(int pos) 
    {
        if (head == NULL)
            return;

            if (head->next == head) 
            {
            delete head;
            head = NULL;
            return;
            }

        if (pos == 1) 
        {
            DNode* last = head->prev;
            DNode* temp = head;

            head = head->next;

            last->next = head;
            head->prev = last;

            delete temp;
            return;
        }
        DNode* temp = head;

        for (int i = 1; i < pos && temp->next != head; i++)
            temp = temp->next;

        if (temp != head) 
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
    void display() 
    {
        if (head == NULL) 
        {
            cout << "Circle is empty\n";
            return;
        }
        DNode* temp = head;

        do 
        {
            cout << temp->name << " ";
            temp = temp->next;
        } 
        while (temp != head);

        cout << endl;
    }
};
int main() 
{
    SinglyCircular s;
    DoublyCircular d;

    cout << "SINGLY CIRCULAR LINKED LIST\n";

    s.join("A", 1);
    s.display();

    s.join("B", 2);
    s.display();

    s.join("C", 3);
    s.display();

    s.join("D", 2);
    s.display();

    s.leave(3);
    s.display();

    cout << "\nDOUBLY CIRCULAR LINKED LIST\n";

    d.join("A", 1);
    d.display();

    d.join("B", 2);
    d.display();

    d.join("C", 3);
    d.display();

    d.join("D", 2);
    d.display();

    d.leave(3);
    d.display();

    return 0;
}
