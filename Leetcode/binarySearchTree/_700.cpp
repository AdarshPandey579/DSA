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

bool searchBST(TreeNode* root, int val) {
    if(root==NULL) return false;
    if(root->val == val) return true;
    else if(root->val < val) return searchBST(root->right, val);
    else return searchBST(root->left, val);
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

    bool result = searchBST(root, 3);
    cout<<result<<endl;
    return 0;
}