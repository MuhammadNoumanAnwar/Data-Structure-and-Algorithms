#include <iostream>
using namespace std;

int partition(int array[], int s, int e)
{
    int pivot = array[e];
    int indx = s - 1;
    for (int i = s; i < e; i++)
    {
        if (array[i] < pivot)
        {
            indx++;
            swap(array[i], array[indx]);
        }
    }
    indx++;
    swap(array[e], array[indx]);
    return indx;
}

void Quick(int array[], int s, int e)
{
    if (s < e)
    {
        int p = partition(array, s, e);
        Quick(array, s, p - 1);
        Quick(array, p + 1, e);
    }
}

int main()
{
    int array[] = {2, 33, 3, 200, 77, 11, 23, 32, 99};
    int n = sizeof(array) / sizeof(array[0]);
    Quick(array, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}
