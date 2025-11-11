#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int value){
          val = value;
          right = left= nullptr;
     }
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTorBT(root, LONG_MIN,LONG_MAX);
    }
public:
    bool isValidBSTorBT(TreeNode* root, long minVal, long maxVal){
        if(root == NULL){ return true; }
        if(root->val >= maxVal || root->val <=minVal){
            return false;
        }
        return isValidBSTorBT(root->left,minVal ,root->val) &&
        isValidBSTorBT(root->right, root->val, maxVal);
    }
};
