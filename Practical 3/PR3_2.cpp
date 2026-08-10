// Selection Sort - repeatedly finding the smallest element from the unsorted array and put them in beginning of the sorted array
#include<iostream>
using namespace std;

int main()
{
    int n;
    int temp;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // compairing the elements of array
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n-i-1;j++)
        {
                
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
        }
    }
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}