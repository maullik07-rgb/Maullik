#include <iostream>
#include <vector>
using namespace std;

int getMax(int arr[], int n) {
    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum)
            maximum = arr[i];
    }

    return maximum;
}

void countingSort(int arr[], int n, int exp) {
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Traverse backward to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maximum = getMax(arr, n);

    for (int exp = 1; maximum / exp > 0; ) {
        countingSort(arr, n, exp);

        if (exp > maximum / 10)
            break;

        exp *= 10;
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;

    radixSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
