#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIGITS 4

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\n",arr[i]);
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[64] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 64]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 64; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 64] - 1] = arr[i];
        count[(arr[i] / exp) % 64]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 64)
        countSort(arr, n, exp);
}
void random_num(int list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        int res=1;
        for (int k = 0; k < 24; k++) {
            if (rand() % 2 == 1)
                sum += res;
            res*=2;
        }
        list[i] = sum;
    }
}

// Driver Code
int main()
{
    srand(time(NULL));
    int arr[1000];
    random_num(arr,1000);
    radixsort(arr, 1000);
    print(arr, 1000);
    return 0;
}

