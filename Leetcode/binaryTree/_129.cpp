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

int sum=0;

int sumNumbers(TreeNode* root, int x=0) {
    if(root==NULL) return 0;
    x= x*10 + root->val;
    if(root->left==NULL && root->right==NULL) sum+=x;
    sumNumbers(root->left, x);
    sumNumbers(root->right, x);
    return sum;
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    /*
              1
            /   \
           2     3
    */

    int ans = sumNumbers(root);
    cout<<ans<<endl;
    return 0;
}