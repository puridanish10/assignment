#include <iostream>
using namespace std;

// maximum size of stack
#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    // initializing an empty stack
    // when top == -1 ; stack is empty    
    Stack() {
        top = -1; 
    }

    // (i) Push operation
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << ". Stack is full." << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack successfully." << endl;
    }

    // (ii) Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack successfully." << endl;
    }

    // (iii) Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // (iv) Check if stack is full 
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // (v) Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // (vi) Peek i.e. view top element without removing
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No element to peek." << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }
};

int main() {
    Stack s;
    int choice, value;
    
    cout << "===== Stack Operations Menu =====" << endl;
    
    do {
        cout << "\nPlease choose an operation:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
                
            case 2:
                s.pop();
                break;
                
            case 3:
                if (s.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
                
            case 4:
                if (s.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
                
            case 5:
                s.display();
                break;
                
            case 6:
                s.peek();
                break;
                
            case 7:
                cout << "Exiting program. Thank you!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please enter a number between 1-7." << endl;
        }
        
    } while (choice != 7);
    
    return 0;
}

