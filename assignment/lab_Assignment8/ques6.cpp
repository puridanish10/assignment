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



class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return build(preorder, inorder, preIndex,0,inorder.size()-1);
    }
public:
TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd){

        if(inStart > inEnd){
            return nullptr;
        }
    TreeNode* root = new TreeNode(preorder[preIndex++]);

    // find root position in inorder array
    int inIndex = -1;
    for(int i =inStart; i<= inEnd; i++){
        if(inorder[i] == root->val){
            inIndex = i;
            break;
        }
    }
    //building left and right subtrees
    root->left = build(preorder,inorder, preIndex, inStart, inIndex-1);
    root->right = build(preorder,inorder,preIndex, inIndex+1, inEnd);
    return root;
}
};
