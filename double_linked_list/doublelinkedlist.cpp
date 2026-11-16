#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void insertEnd(Node*& head, int value) {
    Node* node = new Node(value);
    if (!head) { head = node; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    node->prev = cur;
}

void displayForward(Node* head) {
    while (head) { cout << head->data << " <-> "; head = head->next; }
    cout << "NULL\n";
}

void displayBackward(Node* head) {
    if (!head) return;
    while (head->next) head = head->next;
    while (head) { cout << head->data << " <-> "; head = head->prev; }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 10); insertEnd(head, 20); insertEnd(head, 30);
    cout << "Forward: "; displayForward(head);
    cout << "Backward: "; displayBackward(head);
    while (head) { Node* t = head; head = head->next; delete t; }
}