#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to append a new node at the end
void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Function to count occurrences and delete all of them
int countAndDelete(Node*& head, int key) {
    int count = 0;

    // Delete key occurrences from the head
    while (head && head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        count++;
    }

    // Delete key occurrences in the rest of the list
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        if (current->data == key) {
            count++;
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return count;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    // Creating linked list: 1->2->1->2->1->3->1
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        append(head, arr[i]);

    int key = 1;
    cout << "Original Linked List: ";
    printList(head);

    int count = countAndDelete(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}
