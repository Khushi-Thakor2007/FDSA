// bubble sort - repeatedly swapping the adjacent elements if they are in wrong order
#include<iostream>
using namespace std;

int main()
{ 
    int n;
    int temp;
    //user enter the size of array.
    cout<<"Enter the size of array: ";
    cin>>n;
    //declare the array of size n
    int a[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // compairing the elements of array
    // handle the number of passes
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++) // handle the number of comparision
        {
                if(a[j]>a[j+1]) // if current element is greater then the next , swap them
                {
                    temp=a[j];  
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
        }
    }
    cout<<"The sorted array is: "; // print the sorted array 
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}