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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) return root;

        TreeNode* Left = lowestCommonAncestor(root->left, p, q);
        TreeNode* Right = lowestCommonAncestor(root->right, p, q);

        if(Left && Right) return root;
        else if(Left != NULL) return Left;
        else return Right;
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

    TreeNode* p = new TreeNode(4);
    TreeNode* q = new TreeNode(3);
    // TreeNode* q = new TreeNode(5);

    TreeNode* result = lowestCommonAncestor(root, p, q);
    cout << result->val << endl;

    return 0;
}