// we are given 20 elements ; let the number of elements be n=20 ;
// first 10 elements are sorted and the 11th element is to be inserted in the sorted array

#include <iostream>
using namespace std;

int main()
{
    int A[20] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
                 1, 2, 3, 4, 5, 6, 7, 8, 9, 11};

    int key, j;

    key = A[10];
    j = 9;

    while (j >= 0 && A[j] > key)
    {
        A[j + 1] = A[j];
        j--;
    }

    A[j + 1] = key;

    cout << "Array after sorting first 11 elements:" << endl;

    for (int i = 0; i < 20; i++)
    {
        cout << A[i] << " ";
    }

    return 0;

