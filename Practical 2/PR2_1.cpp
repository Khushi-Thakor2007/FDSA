#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    string plate[5]; // store the licence plates of the car
    string target;  // store the palte which you want to search
    bool found = false; //initially , assume that plate not found

    cout<<"Enter Number Of Car:"; // user enter the car number
    cin>>n;

    cout<<"Enter licence plates:\n"; // take licence plates
    for(int i=0;i<n;i++)
    {
        cin>>plate[i];
    }
    cout<< "Enter The Target Plate:"; // user enter target plate
    cin>>target;

    for(int i =0;i<n;i++)
    {
        if(plate[i]==target) // compare current plate to the target plate
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