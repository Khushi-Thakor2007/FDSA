# include <iostream>
#include <string>
using namespace std;

int main() 
{
    string sentence="Hello Lets learn DataStructureAndAlgorithm together";
    cout << sentence << endl;
    int length=0 , longest=0 , endIndex=0;
    for(int i=0; i<sentence.length(); i++)
    {
        if(sentence[i]==' ')
        {
            if(length>longest)
            {
                longest=length;
                endIndex=i-1;
            }
            length=0;
        }
        else
        {
            length++;
        }
    }
    if(length>longest)
    {
        longest=length;
        endIndex=sentence.length();
    
    }
    cout << "Longest word is: ";
    for(int i=endIndex-longest; i<endIndex; i++)
    {
        cout << sentence[i+1];
    }
    cout << endl;

    return 0;
}