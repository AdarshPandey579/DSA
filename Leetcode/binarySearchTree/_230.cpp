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

priority_queue<int> mh;
int kthSmallest(TreeNode* root, int k) {
    if(root==NULL) return 0;
    kthSmallest(root->left, k);
    if(mh.size()<k) mh.push(root->val);
    kthSmallest(root->right, k);
    return mh.top();
}

int main(){
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(15);
    root->right = new TreeNode(40);
    root->left->right = new TreeNode(18);

    /*
              20            
            /   \
           15     40
            \
             18
    */

    int k = 1;
    int result = kthSmallest(root, k);
    cout<<result<<endl;
    return 0;
}