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

int ans = 0;

int diameterOfBinaryTree(TreeNode* root){
    if(root==NULL) return 0;
    int Left = diameterOfBinaryTree(root->left);
    int Right = diameterOfBinaryTree(root->right);
    ans=max(ans, Left+Right);
    return max(Left, Right)+1;
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

    diameterOfBinaryTree(root);
    cout<<ans<<endl;
    return 0;
}

