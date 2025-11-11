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

int DLLSize(Node* head){
     if(head==NULL){
          return 0;
     }
     Node* temp = head;
     int counter = 0;
     while(temp !=NULL){
          temp = temp->next;
          counter++;
     }
     return counter;
     
}
