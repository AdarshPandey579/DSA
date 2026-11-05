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

int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        if(root->left==NULL) return minDepth(root->right) + 1;
        if(root->right==NULL) return minDepth(root->left) + 1;     

        int Left = minDepth(root->left);
        int Right = minDepth(root->right);
        return min(Left + 1, Right +1) ;
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

    cout<<minDepth(root)<<endl;
    return 0;
}