#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// Get height of a node
int getHeight(Node* root) {
    if (root == nullptr)
        return 0;

    return root->height;
}

// Calculate balance factor
int getBalance(Node* root) {
    if (root == nullptr)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// Insert a node
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root; // Ignore duplicate values

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find minimum value node
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;

    return root;
}

// Delete a node
Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return nullptr;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Node has zero or one child
        if (root->left == nullptr ||
            root->right == nullptr) {

            Node* child = root->left
                          ? root->left
                          : root->right;

            delete root;
            return child;
        }

        // Node has two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right,
                                 temp->data);
    }

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR Case
    if (balance > 1 &&
        getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL Case
    if (balance < -1 &&
        getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Search
bool search(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

// Inorder: Left, Root, Right
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder: Root, Left, Right
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left, Right, Root
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Free allocated memory
void destroyTree(Node* root) {
    if (root == nullptr)
        return;

    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n\n--- AVL TREE ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Inorder";
        cout << "\n5. Preorder";
        cout << "\n6. Postorder";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                cout << "Insertion completed.";
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Deletion completed.";
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;

                if (search(root, value))
                    cout << "Value found.";
                else
                    cout << "Value not found.";
                break;

            case 4:
                cout << "Inorder: ";
                inorder(root);
                break;

            case 5:
                cout << "Preorder: ";
                preorder(root);
                break;

            case 6:
                cout << "Postorder: ";
                postorder(root);
                break;

            case 7:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice.";
        }

    } while (choice != 7);

    destroyTree(root);

    return 0;
}
