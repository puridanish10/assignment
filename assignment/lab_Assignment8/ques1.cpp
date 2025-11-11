#include<bits/stdc++.h>
using namespace std;

class Node{
public:
     int value;
     Node* left;
     Node* right;
     Node(int val){
          value =val;
          right = left =nullptr;
     }
};
void PreOrder(Node* root){
     if(root == nullptr){
          return;
     }
     cout<< root->value <<" ";
     PreOrder(root->left);
     PreOrder(root->right);
}
void InOrder(Node* root){
     if(root == nullptr){
          return;
     }
     InOrder(root->left);
     cout<<root->value << " ";
     InOrder(root->right);
}
void PostOrder(Node* root){
     if(root == nullptr){return;}
     PostOrder(root->left);
     PostOrder(root->right);
     cout<<root->value<<" ";
}
