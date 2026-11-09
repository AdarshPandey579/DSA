#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root) {
    if(root==NULL) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode* Left = root->left;
    TreeNode* Right = root->right;
    if(Left){
        root->left=NULL;
        root->right=Left;
        while(Left->right!=NULL) Left = Left->right;
        Left->right=Right;
    }
}


int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    /*
              4            
            /   \
           2     7
          / \
         1   3
    */

    flatten(root);
    /* 
        4
        \
         2
          \
           1
            \
             3
              \
               7
    */
    while(root){
        cout<<root->val<<" ";
        root=root->right;
    }
    
    return 0;
}