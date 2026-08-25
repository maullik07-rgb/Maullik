#include <iostream>
using namespace std;

int main()
{
    int a[] = {115, 100, 38, 569, 917, 105};
    int n = 6;

    int bucket[10][10] = {0};
    int count[10] = {0};

    // Put numbers into buckets
    for (int i = 0; i < n; i++)
    {
        int index = a[i] / 100;
        bucket[index][count[index]++] = a[i];
    }

    // Sort each bucket
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count[i] - 1; j++)
        {
            for (int k = 0; k < count[i] - j - 1; k++)
            {
                if (bucket[i][k] > bucket[i][k + 1])
                {
                    int temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    // Collect elements
    cout << "Sorted array: ";

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            cout << bucket[i][j] << " ";
        }
    }

    return 0;
}