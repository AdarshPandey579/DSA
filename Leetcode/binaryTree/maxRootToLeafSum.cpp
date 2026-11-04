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

int maxRootToLeafSum(TreeNode* root){
    if(root==NULL) return 0;
    int Left = maxRootToLeafSum(root->left);
    int Right = maxRootToLeafSum(root->right);
    int ans = root->val + max(Left, Right);
    return ans;
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

    int result = maxRootToLeafSum(root);
    cout<<result<<endl;
    return 0;
}