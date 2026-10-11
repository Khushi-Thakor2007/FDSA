#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of IDs: ";
    cin>>n;
    long long table[10];
    bool occupied[10]={false};
    for(int i=0;i<10;i++)
    {
        table[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        long long id;
        cout<<"Enter ID: ";
        cin>>id;
        int start=id%10;
        if(start<0)
        {
            start+=10;
        }
        int jump=1+(id%9+9)%9;
        int slot=-1;
        for(int attempt=0;attempt<10;attempt++)
        {
            int index=(start+attempt*jump)%10;
            if(!occupied[index])
            {
                slot=index;
                break;
            }
        }
        if(slot==-1)
        {
            cout<<"Table full or no reachable slot for ID "
                <<id<<"\n";
        }
        else
        {
            table[slot]=id;
            occupied[slot]=true;
        }
    }
    cout<<"\nFinal hash table:\n";
    for(int i=0;i<10;i++)
    {
        cout<<i<<": ";
        if(occupied[i])
        {
            cout<<table[i];
        }
        else
        {
            cout<<"Empty";
        }
        cout<<"\n";
    }
    return 0;
}