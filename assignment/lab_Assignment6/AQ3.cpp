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


Node* reverseKGroup(Node* head, int k) {
     if(head == NULL || k<=1){
          return head;
     }
     stack<Node*> st;
     Node* current = head;
     Node* newHead = nullptr;
     Node* prevTail = nullptr;

     while(current != NULL){
          int count = 0;
          Node* groupStart = current;

          while(current!=NULL && count == k){
               st.push(current);
               current = current->next;
               count++;
          }
          // if count ==k then its time to reverse the DLL
          if(count == k){
               Node* groupHead = st.top();
               st.pop();
          
          if(prevTail){
               prevTail->next = groupHead;
               groupHead->back = prevTail;
          }
          else{
               newHead = groupHead;
               groupHead->back = nullptr;
          }
          
          Node* temp = groupHead;
          while(!st.empty()){
               Node* nextNode = st.top();
               st.pop();
               temp->next = nextNode;
               nextNode->back = temp;
               temp = nextNode;
          }
          temp->next = current;
          if(current!=NULL){
               current->back = temp;
          }
          prevTail = temp;
     }
     else{
          // Not enough NODES -- therefore K>SizeOfDLL
          if(prevTail){
               prevTail->next = groupStart;
               groupStart->back = prevTail;
          }
          else{
               newHead= groupStart;
          }
     }
     return newHead;
     }
}
