#include<bits/stdc++.h>
using namespace std;

class Node{
public:
     int val;
     Node* right;
     Node* left;
     Node(int value){
          val = value;
          left = right = nullptr;
     }
};


//PART A -> SEARCH in BST
bool Search(Node* root, int target){
     if(!root){ return 0; }
     if(root->val == target){
          return 1;
     }
     if(root->val > target){
          return Search(root->left, target);
     }
     else{
          return Search(root->right, target);
     }
}
