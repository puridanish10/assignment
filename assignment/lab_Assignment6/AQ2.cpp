#include <iostream>
using namespace std;

int get_parity(int n);

class Node{
public:
    int data;
    Node *next, *prev;

    Node(int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

void deleteSpecificNode(int existingvalue){
        Node* temp = head;
        while(temp != nullptr && temp->data != existingvalue){
            temp = temp->next;
        }
        if(temp == nullptr){
            cout << "Value not found!";
        }
        else if(temp == head) { 
            head = head->next;
            head->prev = nullptr;
            temp->next = nullptr; 
        }

        else if(temp->next == nullptr){
            temp->prev->next = nullptr;
        }
        
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete(temp);
    }
   
   
   void deleteAtevenParity(){
        if(head == nullptr){
            cout << "Linked List is empty! Nothing to delete.";
        }
        else{
            Node* temp = head;
            while(temp != nullptr){
                Node* nextNode = temp->next;
                int parity = get_parity(temp->data);
                if(parity % 2 == 0){
                    deleteSpecificNode(temp->data);
                }
                temp = nextNode;
            }
        }
    }
};

int get_parity(int n){
    string binary = "";
    while(n > 0){
        binary = to_string(n % 2) + binary;
        n /= 2;
    }

    int count = 0;
    for(int i = 0; i < binary.length(); i++){
        if(binary[i] == '1'){
            count++;
        }
    }
    return count;
}
