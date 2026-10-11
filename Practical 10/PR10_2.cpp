#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of books: ";
    cin>>n;
    vector<int> shelves[10];
    for(int i=0;i<n;i++)
    {
        int code;
        cout<<"Enter book code: ";
        cin>>code;
        int shelf=code%10;
        if(shelf<0)
        {
            shelf+=10;
        }
        shelves[shelf].push_back(code);
    }
    cout<<"\nFinal bookshelf:\n";
    for(int i=0;i<10;i++)
    {
        cout<<i<<":";
        if(shelves[i].empty())
        {
            cout<<" Empty";
        }
        else
        {
            for(int code:shelves[i])
            {
                cout<<" "<<code;
            }
        }
        cout<<"\n";
    }
    return 0;
}