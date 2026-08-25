// algorithm for radix sorting using arrays 
// list of numbers 038, 100, 105, 115, 569, 917

#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    int A[6] = {38, 100, 105, 115, 569, 917};
    int max = A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n]; // output array
        int count[10] = {0}; // count array

        for (int i = 0; i < n; i++) {
            count[(A[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(A[i] / exp) % 10] - 1] = A[i];
            count[(A[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            A[i] = output[i];
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

