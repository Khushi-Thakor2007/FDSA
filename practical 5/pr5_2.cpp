#include <iostream>
using namespace std;
struct SNode //singly circular linked list
{
    int data; // stors the student's number
    SNode* next; // stores the address of the next student
};

SNode* shead = NULL; //points the first student of singly link list
void singlyJoin(int value) // student can join the circle any time
{
    SNode* newNode = new SNode; //creating a new node
    newNode->data = value; // store the student's number in the new node
    if (shead == NULL) // no student in circle
    {
        shead = newNode; // make the new node the first student
        newNode->next = shead;//circular linked list so student point back to  itself
        return; // stop the function
    }
    SNode* temp = shead; // stats from the first student
    while (temp->next != shead) // move to the last student   // The last student's next points back to shead
    {
        temp = temp->next; // move temp to the next student
    }
    temp->next = newNode;  // Connect the last student to the new student
    newNode->next = shead;// Connect the new student back to the first student
}
void singlyLeave(int value) // student can leave the circle at any time
{
    if (shead == NULL)//list is empty
        return; // stop the function because there is no student to remove
    if (shead->data == value && shead->next == shead)//there is only one student which we wanted to leave(delete)
    {
        delete shead; // delete the only student from memory
        shead = NULL; // make the list empty
        return; // stop the function
    }
    SNode* temp = shead;  // Start searching from the first student
    SNode* prev = NULL;   // 'prev' will store the previous student's address
    do
    {
        prev = temp;// Store the current node as the previous node
        temp = temp->next;  // Move to the next student
        if (temp->data == value)// Check if the next student is the student we want to remove
        {
            prev->next = temp->next;//Connect the previous student directly to the student after the one being removed

            if (temp == shead)// If the student being removed is the first student
                shead = temp->next;  // Move the head to the next student
            delete temp; // delete the student from memory
            return; // stop the function after deleting the student
        }
    } 
    while (temp != shead);  // Continue until we come back to the first student
}
void singlyDisplay() //Display the list
{
    if (shead == NULL)  // Check if the circle is empty
    {
        cout << "Singly Circle is empty\n"; // display message when the circle is empty
        return; // stop the function
    }
    SNode* temp = shead;    // Start from the first student
    cout << "Singly Circular: "; // display the name of the list
    do  // Display each student
    {
        cout << temp->data << " "; // display the current student's number
        temp = temp->next; // move to the next student
    } while (temp != shead); // continue until temp reaches the first student again
    cout << endl; // move to the next line
}
struct DNode //Doubly circular linked list
{
    int data; // stores the student's number
    DNode* prev; // stores the address of the previous student
    DNode* next; // stores the address of the next student
};
DNode* dhead = NULL; // points to the first student of the doubly circular linked list
void doublyJoin(int value) //student can join the circle any time
{
    DNode* newNode = new DNode; // create a new node
    newNode->data = value; // store the student's number in the new node
    if (dhead == NULL) // check if the circle is empty
    {
        dhead = newNode; // make the new node the first student
        newNode->next = dhead; // the new student's next points to itself
        newNode->prev = dhead; // the new student's previous also points to itself
        return; // stop the function
    }
    DNode* last = dhead->prev; // get the last student using the previous link of the first student
    newNode->next = dhead; // new student's next points to the first student
    newNode->prev = last; // new student's previous points to the last student
    last->next = newNode; // last student's next points to the new student
    dhead->prev = newNode; // first student's previous points to the new student
}
void doublyLeave(int value) // student can leave the circle at any time
{
    if (dhead == NULL) // check if the circle is empty
        return; // stop the function if there is no student
    DNode* temp = dhead; // start searching from the first student
    do
    {
        if (temp->data == value) // check if the current student is the student to remove
            break; // stop searching when the student is found
        temp = temp->next; // move to the next student
    }
    while (temp != dhead); // continue until we reach the first student again
    if (temp->data != value) // check if the student was not found
        return; // stop the function
    if (temp->next == temp) // check if there is only one student in the circle
    {
        delete temp; // delete the only student
        dhead = NULL; // make the circle empty
        return; // stop the function
    }
    temp->prev->next = temp->next; // connect the previous student to the next student
    temp->next->prev = temp->prev; // connect the next student back to the previous student
    if (temp == dhead) // check if the student being removed is the first student
        dhead = temp->next; // make the next student the new first student
    delete temp; // delete the student from memory
}
void doublyDisplay() // It will display the list
{
    if (dhead == NULL) // check if the circle is empty
    {
        cout << "Doubly Circle is empty\n"; // display message when the circle is empty
        return; // stop the function
    }
    DNode* temp = dhead; // start from the first student
    cout << "Doubly Circular: "; // display the name of the list
    do
    {
        cout << temp->data << " "; // display the current student's number
        temp = temp->next; // move to the next student
    } while (temp != dhead); // continue until temp reaches the first student again
    cout << endl; // move to the next line
}
int main()
{
    singlyJoin(1); // add student 1 to the singly circular list
    singlyJoin(2); // add student 2 to the singly circular list
    singlyJoin(3); // add student 3 to the singly circular list

    doublyJoin(1); // add student 1 to the doubly circular list
    doublyJoin(2); // add student 2 to the doubly circular list
    doublyJoin(3); // add student 3 to the doubly circular list

    cout << "After students join:\n"; // display message after students join
    singlyDisplay(); // display the singly circular list
    doublyDisplay(); // display the doubly circular list

    singlyLeave(2); // remove student 2 from the singly circular list
    doublyLeave(2); // remove student 2 from the doubly circular list

    cout << "\nAfter student 2 leaves:\n"; // display message after student 2 leaves
    singlyDisplay(); // display the singly circular list
    doublyDisplay(); // display the doubly circular list

    singlyJoin(4); // add student 4 to the singly circular list
    doublyJoin(4); // add student 4 to the doubly circular list

    cout << "\nAfter student 4 joins:\n"; // display message after student 4 joins
    singlyDisplay(); // display the singly circular list
    doublyDisplay(); // display the doubly circular list

    return 0; // end the program successfully
}