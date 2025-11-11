#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
     int data;
     Node *next;
     Node *back;

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

bool checkCLL(Node *head)
{ 
     if(head == nullptr){
          return true;
     }

     Node* slow = head;
     Node* fast = head;
     
     while(fast != nullptr && fast->next != nullptr){
          slow = slow->next;
          fast = fast->next->next;
          
          //if they meet -- its a cycle
          if(slow == fast) {
               break;
          }
     
     } 
     // if fast reached nullptr => no cylce
     if(fast == nullptr || fast->next == nullptr){
          return false;
     }

     slow = head;
     while(slow != fast){
          slow = slow->next;
          fast = fast->next;
     }

     // if cycle starts at head-->> its circular
     return (slow == head);
}
