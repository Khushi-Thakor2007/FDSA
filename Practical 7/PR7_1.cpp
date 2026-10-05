#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int n;
    int front;
    int rear;
    int count;
public:
    Queue(int size)
    {
        n = size;
        arr = new int[n];

        front = 0;
        rear = -1;
        count = 0;
    }
    void join(int token)
    {
        if (count == n)
        {
            cout << "Error: Queue is full. Cannot issue token "
                 << token << endl;
            return;
        }
        rear = (rear + 1) % n;
        arr[rear] = token;
        count++;
        cout << "After Join " << token
             << " -> Front: " << arr[front] << endl;
    }
    void serve()
    {
        if (count == 0)
        {
            cout << "Error: Queue is empty. Cannot serve." << endl;
            return;
        }
        cout << "Serving token: " << arr[front] << endl;
        front = (front + 1) % n;
        count--;
        if (count == 0)
        {
            front = 0;
            rear = -1;
        }
        if (count > 0)
        {
            cout << "After Serve -> Front: "
                 << arr[front] << endl;
        }
        else
        {
            cout << "After Serve -> Queue is empty" << endl;
        }
    }
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    int n, operations;

    cout << "Enter maximum capacity: ";
    cin >> n;

    Queue q(n);

    cout << "Enter number of operations: ";
    cin >> operations;

    cout << "\nOperations:\n";
    cout << "1 = Join\n";
    cout << "2 = Serve\n\n";

    for (int i = 0; i < operations; i++)
    {
        int choice;

        cout << "Enter operation: ";
        cin >> choice;

        if (choice == 1)
        {
            int token;
            cout << "Enter token number: ";
            cin >> token;

            q.join(token);
        }
        else if (choice == 2)
        {
            q.serve();
        }
        else
        {
            cout << "Error: Invalid operation." << endl;
        }
    }

    return 0;
}