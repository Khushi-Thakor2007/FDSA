#include <iostream>//radix sort
using namespace std;

int getMax(int a[], int n) //make a function to take the max number
{
    int max = a[0]; // take first element as a max number

    for(int i = 1; i < n; i++) // compare other element with the max
    {
        if(a[i] > max)
            max = a[i];
    }

    return max; // return the max element
}

void countingSort(int a[], int n, int place) // Counting Sort sorts the numbers based on one digit at a time.
{
    int output[n]; // store the sorted result
    int count[10] = {0};

    // Count occurrences of each digit
    for(int i = 0; i < n; i++)
    {
        int digit = (a[i] / place) % 10; //find the digit at given place like 
                                        // 1=units digit , 10=tens digit , 100=hundreds digit
        count[digit]++; // increase the count of digits
    }

    // Find the actual position of each digit
    for(int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // place elements into the output array
    for(int i = n - 1; i >= 0; i--)
    {
        int digit = (a[i] / place) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--; // decrease the posision for the next 
    }

    // Copy sorted elements back to original array
    for(int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

// Radix Sort
void radixSort(int a[], int n)
{
    int max = getMax(a, n); // find the largest number

    // Start from units digit, then tens, hundreds, etc.
    for(int place = 1; max / place > 0; place = place * 10)
    {
        countingSort(a, n, place);
    }
}

int main()
{
    int n;

    cout << "Enter number of tracking codes: ";
    cin >> n;

    int a[n];

    cout << "Enter tracking codes: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    radixSort(a, n);

    cout << "Sorted tracking codes: "; // display the sorted array
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}