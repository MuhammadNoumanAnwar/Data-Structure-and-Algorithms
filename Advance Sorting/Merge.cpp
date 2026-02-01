#include <iostream>
using namespace std;
void merge(int arr[], int s, int mid, int e)
{
    int n1 = mid - s + 1;
    int n2 = e - mid;
    int *left = new int[n1];
    int *right = new int[n2];
    
    for (int i = 0; i < n1; i++)
        left[i] = arr[s + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}

void mergesort(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        mergesort(arr, s, mid); //[1]
        mergesort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

int main()
{
    int arr[] = {99, 73, 33, 58, 24, 222};
    int n = 6;

    mergesort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
