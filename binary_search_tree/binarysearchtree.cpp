#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a value
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


// Search for a value
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }


    if (root->data == key) {
        return true;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Inorder: Left, Root, Right
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder: Root, Left, Right
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


// Postorder: Left, Right, Root
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


// Find minimum value
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}

// Delete a value
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    else {
        // Case 1: No child
        if (root->left == nullptr &&
            root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }


        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Free all allocated nodes
void destroyTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;

    // Create the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);


    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";

    preorder(root);


    cout << "\nPostorder: ";
    postorder(root);

    int key = 40;

    cout << "\n\nSearching for " << key << ": ";
    if (search(root, key)) {
        cout << "Found";
    }
    else {
        cout << "Not found";
    }

    root = deleteNode(root, 30);

    cout << "\nInorder after deleting 30: ";
    inorder(root);

    cout << endl;

    destroyTree(root);

    return 0;
}