#include <iostream>
#include <string>
using namespace std;
struct Node // create the node of the linked list
{
    string song;
    Node* prev;
    Node* next;
};
void addBeginning(Node*& head,string song) // add the song at the biginning of the linked list
{
    Node* newNode=new Node();
    newNode->song=song;
    newNode->prev=nullptr;
    newNode->next=head;

    if(head!=nullptr)
    {
        head->prev=newNode;
    }
    head=newNode;
}
void addEnd(Node*& head,string song) // inseart at last position in linked list
{
    Node* newNode=new Node();
    newNode->song=song;
    newNode->next=nullptr;
    if(head==nullptr)
    {
        newNode->prev=nullptr;
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr)
    {
       temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void addinbetween(Node* head,string givensong,string newsong)
{
    Node* temp=head;
    while(temp!=nullptr && temp->song!=givensong)
    {
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"Song not found!"<<endl;
        return;
    }
    Node* newNode = new Node();
    newNode->song = newsong;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }
     temp->next = newNode;
}
void removeFirst(Node*& head)
{
    if (head == nullptr)
    {
        cout << "Playlist is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
}
int countSongs(Node* head)
{
    int count = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void display(Node* head)
{
    Node* temp = head;
    cout << "Playlist: ";
    while (temp != nullptr)
    {
        cout << temp->song << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node* head = nullptr;
    addBeginning(head, "SongA");
    display(head);

    addEnd(head, "SongB");
    display(head);

    addBeginning(head, "SongC");
    display(head);

    addinbetween(head, "SongA", "SongD");
    display(head);

    cout << "Number of songs: " << countSongs(head) << endl;

    removeFirst(head);
    display(head);

    cout << "Number of songs: " << countSongs(head) << endl;

    return 0;
}
