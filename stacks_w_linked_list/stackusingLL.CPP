#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;
    cout << "Deleted: " << temp->data << endl;
    top = top->next;
    delete temp;
}

void display() {
    Node* temp = top;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Stack: ";
    display();

    pop();

    cout << "After deletion: ";
    display();

    return 0;
}