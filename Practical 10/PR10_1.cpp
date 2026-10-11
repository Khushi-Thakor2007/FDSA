#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of vehicles: ";
    cin>>n;
    long long slots[10];
    bool occupied[10]={false};
    for(int i=0;i<10;i++)
    {
        slots[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        long long registration;
        cout<<"Enter registration number: ";
        cin>>registration;
        int start=registration%10;
        if(start<0)
        {
            start+=10;
        }
        int slot=start;
        int checked=0;
        while(checked<10 && occupied[slot])
        {
            slot=(slot+1)%10;
            checked++;
        }
        if(checked==10)
        {
            cout<<"Parking lot full. Vehicle "
                <<registration
                <<" could not be parked.\n";
        }
        else
        {
            slots[slot]=registration;
            occupied[slot]=true;
        }
    }
    cout<<"\nFinal parking lot:\n";
    for(int i=0;i<10;i++)
    {
        cout<<i<<": ";

        if(occupied[i])
        {
            cout<<slots[i];
        }
        else
        {
            cout<<"Empty";
        }
        cout<<"\n";
    }
    return 0;
}