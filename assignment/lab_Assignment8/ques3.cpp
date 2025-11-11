#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int value){
          val =value;
          right = left =nullptr;
     }
};

// (A)INSERT AN ELEMENT
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* current = root;
        while(true){
            // if value of root is <= value of Node to be inserted
            if(current->val <= val){
                if(current->right != NULL) current = current->right;
                else{ 
                    current->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(current->left!=NULL){
                    current = current->left;
                }
                else{
                    current->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }

// (B) DELETE AN EXISTING ELEMENT
