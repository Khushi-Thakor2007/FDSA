#include<iostream>
using namespace std;
struct SNode
{
    int data;
    SNode* next;
};
SNode* shead = NULL;
void singlyJoin(int value)
{
    SNode* newNode = new SNode;
    newNode->data = value;
    if (shead == NULL)
    {
        shead = newNode;
        newNode->next = shead;
        return;
    }
    SNode* temp = shead;
    while (temp->next != shead)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = shead;
}
void singlyLeave(int value)
{
    if (shead == NULL)
        return;
    if (shead->data == value && shead->next == shead)
    {
        delete shead;
        shead = NULL;
        return;
    }
    SNode* temp = shead;
    SNode* prev = NULL;
    do
    {
        prev = temp;
        temp = temp->next;
        if (temp->data == value)
        {
            prev->next = temp->next;

            if (temp == shead)
                shead = temp->next;
            delete temp;
            return;
        }
    }
    while (temp != shead);
}
void singlyDisplay()
{
    if (shead == NULL)
    {
        cout << "Singly Circle is empty\n";
        return;
    }
    SNode* temp = shead;
    cout << "Singly Circular: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != shead);
    cout << endl;
}
struct DNode
{
    int data;
    DNode* prev;
    DNode* next;
};
DNode* dhead = NULL;
void doublyJoin(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    if (dhead == NULL)
    {
        dhead = newNode;
        newNode->next = dhead;
        newNode->prev = dhead;
        return;
    }
    DNode* last = dhead->prev;
    newNode->next = dhead;
    newNode->prev = last;
    last->next = newNode;
    dhead->prev = newNode;
}
void doublyLeave(int value)
{
    if (dhead == NULL)
        return;
    DNode* temp = dhead;
    do
    {
        if (temp->data == value)
            break;
        temp = temp->next;
    }
    while (temp != dhead);
    if (temp->data != value)
        return;
    if (temp->next == temp)
    {
        delete temp;
        dhead = NULL;
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if (temp == dhead)
        dhead = temp->next;
    delete temp;
}
void doublyDisplay()
{
    if (dhead == NULL)
    {
        cout << "Doubly Circle is empty\n";
        return;
    }
    DNode* temp = dhead;
    cout << "Doubly Circular: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != dhead);
    cout << endl;
}
int main()
{
    singlyJoin(1);
    singlyJoin(2);
    singlyJoin(3);

    doublyJoin(1);
    doublyJoin(2);
    doublyJoin(3);

    cout << "After students join:\n";
    singlyDisplay();
    doublyDisplay();

    singlyLeave(2);
    doublyLeave(2);

    cout << "\nAfter student 2 leaves:\n";
    singlyDisplay();
    doublyDisplay();

    singlyJoin(4);
    doublyJoin(4);

    cout << "\nAfter student 4 joins:\n";
    singlyDisplay();
    doublyDisplay();

    return 0;
}