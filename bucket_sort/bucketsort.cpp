#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = 7;

    vector<vector<float>> buckets(n);

    // Place values into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Combine all buckets
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}