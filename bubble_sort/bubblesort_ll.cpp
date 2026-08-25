#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void bubbleSort(Node* head)
{
    Node* i;
    Node* j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = head; j->next != NULL; j = j->next)
        {
            if (j->data > j->next->data)
            {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

int main()
{
    Node* head = new Node{5, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{8, NULL};
    head->next->next->next = new Node{1, NULL};
    head->next->next->next->next = new Node{3, NULL};

    bubbleSort(head);

    Node* temp = head;

    cout << "Sorted List: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}