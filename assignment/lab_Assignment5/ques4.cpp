#include<bits/stdc++.h>
using namespace std;

class Node{
public:
     int data;
     Node* next;
     Node(int value){
          data = value;
          next = NULL;
     }
};
class List{
     Node* head;
     Node* tail;
public:
     List(){
          head = tail = NULL;
     }
   

     Node* reverseList(Node* head){
          Node* prev = NULL;
          Node* current = head;
          Node* next= NULL;
     
          while(current != NULL){
               next =current->next;
               current->next = prev;

               prev = current;
               current = next;
          }
          return prev; // this is new head of LL
     
     }

     Node* MiddleOfLL(Node* head){
          Node* fast = NULL;
          Node* slow = NULL;
          while(fast!=NULL && fast->next != NULL){
               slow = slow->next;
               fast = fast->next->next;

          }
          return slow;
     }





     void push_front(int value){
          Node* newNode = new Node(value);
          if(head == NULL){// when LL is empty
               head = tail = newNode;
               return;
          }else{// when LL is not empty
               newNode->next = head;
               head = newNode;
          }
     }
     void push_back(int value){
          Node* newNode = new Node(value);
          if(head == NULL){
               head = tail = newNode;
          }else{// when LL is not empty
               tail->next = newNode;
               tail = newNode;
          }
     
     }


     void printLL(){
          Node* temp = head;
          while(temp != NULL){
               cout<< temp->data <<" -> " ;
               temp = temp -> next;
          }
          cout<<"NULL"<<endl;
     }
     void pop_front(){
          if(head==NULL){
               cout<<"LL is Empty"<<endl;
               return;
          }
          Node* temp = head;// giving current head value to tmep
          head = head->next;// pushing head to claim the next value
          temp->next = NULL;//Temp value ie old head is pointing to NULL address
          
          delete temp;
     }

     void pop_back(){
          if(head == NULL){
               cout<<"LL is Empty" << endl;
               return;
          }
          Node* temp = head;
          while(temp->next != tail ){
               temp = temp->next;
          }
          
          // Now since Temp is finally the next one
          temp->next = NULL;
          delete tail;
          tail = temp;
     }
};

int main(){
     List ll; //  declaring a list
     ll.push_front(8);
     ll.push_front(5);
     ll.push_front(4);
   

     ll.printLL();
     cout<<"Middle of LL is at "<<ll.MiddleOfLL()<<endl;
     
     return 0;
}
