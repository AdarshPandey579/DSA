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


int ans = INT_MAX;
int minDiffInBST(TreeNode* root, TreeNode* &prev) {
    if(root == NULL) return ans;
    minDiffInBST(root->left, prev);
    if(prev) ans = min(ans, root->val - prev->val);
    prev=root;
    minDiffInBST(root->right, prev);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    /*
              4            
            /   \
           2     6
          / \
         1   3
    */

    TreeNode* prev = NULL;
    int result = minDiffInBST(root, prev);
    cout<<result<<endl;
    return 0;
}