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

int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    int Left = maxDepth(root->left);
    int Right = maxDepth(root->right);
    return max(Left , Right) + 1 ;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    /*
              1
            /   \
           2     5
                / \
               1   7
                    \
                     8
    */

    cout<<maxDepth(root)<<endl;
    return 0;
}