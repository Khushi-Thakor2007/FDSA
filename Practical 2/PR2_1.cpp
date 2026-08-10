#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    string plate[5];
    string target;
    bool found = false;

    cout<<"Enter Number Of Car:";
    cin>>n;

    cout<<"Enter licence plates:\n";
    for(int i=0;i<n;i++)
    {
        cin>>plate[i];
    }
    cout<< "Enter The Target Plate:";
    cin>>target;

    for(int i =0;i<n;i++)
    {
        if(plate[i]==target)
        {
            cout<<"The target plate found at position:"<<i+1<<endl;
            found=true;
            break;
        }
        if(found == false)
        {
            cout<<"Target plate not found"<<endl;
        }
    }
    
  return 0;
}