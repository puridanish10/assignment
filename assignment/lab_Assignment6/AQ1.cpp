#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};
class CircularLinkedList{
public:
    Node *head;

    CircularLinkedList(){
        head = nullptr;
    }

 int get_size(){
        int size = 1;
        if(head == nullptr){
            return 0;
        }
        else{
            Node* temp = head;
            while(temp->next != head){
                size++;
                temp = temp->next;
            }
            return size;
        }
    }
    void insertAtEnd(int num){
        Node *newNode = new Node(num);
        if(!head){
            head = newNode;
            newNode->next = head;
        }
        else{
            Node *current = head;
            while(current->next != head){
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }
}; 


void splitLinkedList(CircularLinkedList &C, CircularLinkedList &C1, CircularLinkedList &C2){
        int size = C.get_size();
        if (size % 2 == 0 ){
            Node* temp = C.head;
            for(int i = 1; i <= size / 2; i++){
                C1.insertAtEnd(temp->data);
                temp = temp->next;
            }
            for(int i = 1; i <= size / 2; i++){
                C2.insertAtEnd(temp->data);
                temp = temp->next;
            }
        }
        else{
            Node* temp1 = C.head;
            for(int i = 1; i <= (size / 2) + 1; i++){
                C1.insertAtEnd(temp1->data);
                temp1 = temp1->next;
            }
            for(int i = (size / 2) + 1; i < size; i++){
                C2.insertAtEnd(temp1->data);
                temp1 = temp1->next;
            }
        }    
}
