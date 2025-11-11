#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
     int data;
     Node *next;
     Node *back;
     Node* random;

     Node(int data1)
     {
          data = data1;
          next = nullptr;
          back = nullptr;
     }
     Node(int data1, Node *next1, Node *back1)
     {
          data = data1;
          next = next1;
          back = back1;
     }
};

Node* createSampleList() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    
    // Set up next pointers
    head->next = second;
    second->back = head;
    second->next = third;
    third->back = second;
    
    // Set up random pointers (one is incorrect)
    head->random = second;    // Correct: points to next
    second->random = third;   // Correct: points to next  
    third->random = head;     // INCORRECT: should point to NULL (no next)
    
    return head;
}

void correctRandomPointer(Node* head){
     Node* current = head;
     if(head==NULL){
          return;
     }
     while(current!=nullptr){
          Node* expectedRandom = current -> next;
          
          if (current->random != expectedRandom) {
               current->random = expectedRandom;
               break;
          }
        current = current -> next;
     }

}
