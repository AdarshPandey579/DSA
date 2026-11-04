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

bool hasPathSum(TreeNode* root, int targetSum, int x=0) {
    if(root == NULL) return false;
    x+=root->val;
    if(root->left==NULL && root->right==NULL) return targetSum==x;
    bool Left = hasPathSum(root->left , targetSum, x);
    bool Right = hasPathSum(root->right , targetSum, x);
    return Left||Right;
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

    int result = hasPathSum(root, 11);
    cout<<result<<endl;
    return 0;
}