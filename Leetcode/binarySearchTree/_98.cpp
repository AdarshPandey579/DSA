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

bool isValidBST(TreeNode* root, long long min, long long max){
    if(root==NULL) return true;
    if((long long)root->val <= min) return false;
    if((long long)root->val >= max) return false;

    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
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

    bool result = isValidBST(root, LLONG_MIN, LLONG_MAX);
    cout<<result<<endl;
    return 0;
}