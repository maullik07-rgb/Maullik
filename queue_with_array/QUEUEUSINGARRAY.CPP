#include <iostream>
using namespace std;

int a[5], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == 4) {
        cout << "Queue Overflow\n";
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        a[rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
    } else {
        cout << "Deleted: " << a[front] << endl;
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    for (int i = front; i <= rear; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    dequeue();
    display();

    return 0;
}