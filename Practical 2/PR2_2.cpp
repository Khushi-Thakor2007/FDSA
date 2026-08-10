#include <iostream>
#include <string>
using namespace std;

int catalog(string code[], int n, string target) // Simple binary search
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(code[mid] == target)
        {
            return mid;
        }
        else if(code[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int catalog(string code[], int low, int high, string target) // recursive binary search 
{
    if(low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if(code[mid] == target)
    {
        return mid;
    }
    else if(code[mid] < target)
    {
        return catalog(code, mid + 1, high, target);
    }
    else
    {
        return catalog(code, low, mid - 1, target);
    }
}

int main()
{
    int n;
    string code[100];
    string target;

    cout << "Enter number of book codes: ";
    cin >> n;

    cout << "Enter sorted book codes:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> code[i];
    }

    cout << "Enter target code: ";
    cin >> target;

    int result1 =catalog(code, n, target); 

    if(result1 != -1)
    {
        cout << "\nIterative Binary Search:\n";
        cout << "Book code found at position: " << result1 + 1 << endl;
    }
    else
    {
        cout << "\nIterative Binary Search:\n";
        cout << "Book code not found." << endl;
    }

    int result2 = catalog(code, 0, n - 1, target);

    if(result2 != -1)
    {
        cout << "\nRecursive Binary Search:\n";
        cout << "Book code found at position: " << result2 + 1 << endl;
    }
    else
    {
        cout << "\nRecursive Binary Search:\n";
        cout << "Book code not found." << endl;
    }

    return 0;
}