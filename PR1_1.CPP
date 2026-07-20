#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items n ";
    cin >> n ;
    cout<<"enter number of hours h";
    cin >> h;

    if (n == 0)
    {
        return 0;
    }

    int items[n];   

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }

    int shift = h % n; 

    cout << "Final display order: ";
    for (int i = 0; i < n; i++)
    {
        cout << items[(i + shift) % n] << " ";
    }

    cout << endl;

    return 0;
}