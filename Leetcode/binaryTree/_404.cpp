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

int Post(TreeNode* root, int isLeft){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL && isLeft) return root->val;
    int Left = Post(root->left, 1);
    int Right = Post(root->right, 0);
    return Left + Right;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);

    /*
              4            
            /   \
           9     7
                / \
               1   3
    */

    cout<<Post(root, 0)<<endl;
    return 0;
}