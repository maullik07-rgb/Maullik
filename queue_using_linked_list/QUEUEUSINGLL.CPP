#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

// Insert element
void enqueue(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Delete element
void dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << "Deleted: " << temp->data << endl;

    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
}

// Display queue
void display() {
    Node* temp = front;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue: ";
    display();

    dequeue();

    cout << "After deletion: ";
    display();

    return 0;
}