#include <iostream>
using namespace std;

#define MAX 100

int queueArr[MAX];
int front = -1;
int rear = -1;

void arrive(int patient)
{
    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queueArr[rear] = patient;
}

void attend()
{
    if (front == -1 || front > rear)
    {
        cout << "Ward is empty" << endl;
        return;
    }

    cout << "Attended patient: " << queueArr[front] << endl;
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void displayFront()
{
    if (front == -1)
    {
        cout << "Front patient: Ward is empty" << endl;
    }
    else
    {
        cout << "Front patient: " << queueArr[front] << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int choice, patient;

        cout << "\n1. Arrive";
        cout << "\n2. Attend";
        cout << "\nEnter operation: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter patient number: ";
            cin >> patient;

            arrive(patient);
        }
        else if (choice == 2)
        {
            attend();
        }
        else
        {
            cout << "Invalid operation" << endl;
        }

        displayFront();
    }

    return 0;
}