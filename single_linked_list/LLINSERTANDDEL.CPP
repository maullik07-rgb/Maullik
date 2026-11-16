#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(){}
    Node(int d, Node* n)
    {
        data = d;
        next = n;
    }
};

void inserter (Node* &head, int n)
{
    // Node* mover = NULL;
    for (int i = 0; i<n; i++)
    {
        int value;
        cout << "Enter value." << endl;
        cin >> value; 
        Node* newNode = new Node(value, NULL);
        if (head == NULL)
        {
            head = newNode;
            // mover = head;
        }
        else
        {
            Node* mover = head;
            while (mover->next != NULL)
            {
                mover = mover->next;
            }
            mover->next = newNode;
        }
    }
}

void deleter (Node* &head, int value)
{
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data !=value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout <<