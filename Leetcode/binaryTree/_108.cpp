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

TreeNode* func(vector<int>& nums, int st, int end){
    if(st>end) return NULL;
    int mid = st+(end-st)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = func(nums, st, mid-1);
    root->right = func(nums, mid+1, end);
    return root;
}

void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = func(nums, 0, nums.size()-1);
    /*
              0
            /   \
          -3     9
          /     /
        -10    5
    */
    inorder(root);
    return 0;
}