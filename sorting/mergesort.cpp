#include <bits/stdc++.h>
using namespace std;

void printarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mergesort()
{

}

void merge()
{

}


int main()
{
    int arr[] = {6, 2, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, n);

    cout << "Sorted array: \n";
    printarray(arr, n);

    return 0;
}