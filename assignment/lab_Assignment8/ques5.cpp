#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int value){
          val = value;
          left = right = nullptr;
     }
};
class Solution{
public: 

vector<int> inOrderTraversal(TreeNode* root){
     stack<TreeNode*> st;
     vector<int> inorder;
     TreeNode* node = root;
     while(true){
          if(root!=NULL){
               st.push(node);
               root = root->left;
          }
          else{// else here means if root is NULL IE either ONLY theleft side of tree ends or 
               // tree has ended
               if(st.empty() == true) break;

               node = st.top();
               st.pop();
               inorder.push_back(node->val);
               node = node->right;
          }
     }
}

};
