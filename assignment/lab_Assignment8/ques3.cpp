#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *lchild;
    Node *rchild;

    Node(int data) {
        this->data = data;
        lchild = nullptr;
        rchild = nullptr;
    }
};

class BST_implementation {
public:
    Node *root;

    BST_implementation() {
        root = nullptr;
    }

    void insert_unique_element(int value) {
        Node *newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (value < current->data)
                current = current->lchild;
            else if (value > current->data)
                current = current->rchild;
            else {
                cout << "Same values cannot be inserted in the BST!" << endl;
                delete newNode;
                return;
            }
        }

        if (value > parent->data)
            parent->rchild = newNode;
        else
            parent->lchild = newNode;
    }

    Node* min_node(Node* node) {
        Node* current = node;
        while (current && current->lchild != nullptr)
            current = current->lchild;
        return current;
    }

    Node* deleteElement(Node* root, int value) {
        if (root == nullptr)
            return root;

        if (value < root->data)
            root->lchild = deleteElement(root->lchild, value);
        else if (value > root->data)
            root->rchild = deleteElement(root->rchild, value);
        else {
            if (root->lchild == nullptr) {
                Node* temp = root->rchild;
                delete root;
                return temp;
            } else if (root->rchild == nullptr) {
                Node* temp = root->lchild;
                delete root;
                return temp;
            }

            Node* temp = min_node(root->rchild);
            root->data = temp->data;
            root->rchild = deleteElement(root->rchild, temp->data);
        }
        return root;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->lchild);
        cout << node->data << " ";
        inorder(node->rchild);
    }
};

int main() {
    BST_implementation B1;

    B1.insert_unique_element(4);
    B1.insert_unique_element(2);
    B1.insert_unique_element(6);
    B1.insert_unique_element(1);
    B1.insert_unique_element(3);
    B1.insert_unique_element(5);
    B1.insert_unique_element(7);

    cout << "Inorder before deletion: ";
    B1.inorder(B1.root);
    cout << endl;

    B1.root = B1.deleteElement(B1.root, 4);

    cout << "Inorder after deletion: ";
    B1.inorder(B1.root);
    cout << endl;

    return 0;
}
