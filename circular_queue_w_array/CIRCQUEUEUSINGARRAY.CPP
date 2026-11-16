#include <iostream>
using namespace std;

const int CAPACITY = 5;
class CircularQueue {
    int a[CAPACITY], frontIndex, rearIndex, count;
public:
    CircularQueue() : frontIndex(0), rearIndex(-1), count(0) {}
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == CAPACITY; }
    void enqueue(int x) {
        if (isFull()) { cout << "Circular queue is full\n"; return; }
        rearIndex = (rearIndex + 1) % CAPACITY;
        a[rearIndex] = x; ++count;
    }
    void dequeue() {
        if (isEmpty()) { cout << "Circular queue is empty\n"; return; }
        cout << "Removed: " << a[frontIndex] << '\n';
        frontIndex = (frontIndex + 1) % CAPACITY; --count;
    }
    void display() {
        if (isEmpty()) { cout << "Circular queue is empty\n"; return; }
        for (int i = 0; i < count; ++i) cout << a[(frontIndex + i) % CAPACITY] << ' ';
        cout << '\n';
    }
};
int main() {
    CircularQueue q;
    q.enqueue(10); q.enqueue(20); q.enqueue(30); q.enqueue(40);
    q.display(); q.dequeue(); q.dequeue(); q.enqueue(50); q.enqueue(60);
    cout << "After wrap-around: "; q.display();
}