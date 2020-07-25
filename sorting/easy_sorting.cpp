#include <bits/stdc++.h>
using namespace std;

void printarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionsort(int arr[], int n)
{
    int i, j, min_index;

    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
}

void bubblesort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        bool swapped;
        for (j = 0; j < n - 1 - i; j++)
        {
            swapped = false;
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == false)
            break;
    }
}

void insertionsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        //start checking from the back of our key till 0
        //if the element is bigger bring them forward
        //when the loop stop that means we reacherd the
        //correct position place the key value there
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {6, 2, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr, n);

    cout << "Sorted array: \n";
    printarray(arr, n);

    return 0;
}