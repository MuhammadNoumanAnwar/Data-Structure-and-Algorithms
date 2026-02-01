#include <iostream>
using namespace std;
int partition(int a[], int s, int e)
{
    int pivot = a[e];
    int indx = s - 1;
    for (int i = s; i < e; i++)
    {
        if (a[i] < pivot)
        {
            indx++;
            swap(a[i], a[indx]);
        }
    }
    indx++;
    swap(a[indx], a[e]);
    return indx;
}
void quick(int a[], int s, int e)
{
    if (s < e)
    {
        int p = partition(a, s, e);
        quick(a, s, p - 1);
        quick(a, p + 1, e);
    }
}
int main()
{
    int array[7] = {22, 44, 11, 77, 55, 66, 88};
    quick(array, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}