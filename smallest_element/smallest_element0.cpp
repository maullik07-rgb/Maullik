// find the smallest element in array of n elements

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (s.find(x - a) != s.end()) {
            cout << "Pair found: " << a << " and " << x - a << endl;
        }
        s.insert(a);
    }
    return 0;
}

