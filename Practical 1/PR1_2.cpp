#include<iostream>
using namespace std;

int main()
{
    int i, j, count;
    int arr[10] = {2, 5, 4, 8, 4, 2, 5, 6, 8, 2};

    cout << "Array: ";
    for(i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nRepeated Elements:\n";

    for(i = 0; i < 10; i++)
    {
        count = 1;
        for(j = i + 1; j < 10; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }

        if(count > 1)
        {
            cout << arr[i] << " is repeated " << count << " times." << endl;
        }
    }

    return 0;
}