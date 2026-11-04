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

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return root;
    TreeNode* Left = root->left;
    TreeNode* Right = root->right;
    root->left = Right;
    root->right = Left;
    invertTree(Left);
    invertTree(Right);
    return root;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
*/

    TreeNode* ans = invertTree(root);
    cout<<ans->val<<endl;
    cout<<ans->left->val<<" "<<ans->right->val<<endl;
    cout<<ans->left->left->val<<" "<<ans->left->right->val<<" "<<ans->right->left->val<<" "<<ans->right->right->val<<endl;

    return 0;

}