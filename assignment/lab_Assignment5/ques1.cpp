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
     ll.push_front(1);
     ll.push_front(2);
     ll.push_front(3);
     ll.push_back(4);
     
     ll.pop_front();
     
     ll.pop_back();
     ll.printLL();
     return 0;
}
