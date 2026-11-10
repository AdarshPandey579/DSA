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

TreeNode* buildBST(vector<int>& preorder, int& idx, int ub, int n){
    if(idx==n) return NULL;
    if(preorder[idx] > ub) return NULL;
    TreeNode* node = new TreeNode(preorder[idx]);
    idx++;
    node->left = buildBST(preorder, idx, node->val, n);
    node->right = buildBST(preorder, idx, ub, n);
    return node;
}

int main(){
    vector<int> preorder = {8,5,1,7,10,12};
    int idx = 0;
    int n = preorder.size();
    TreeNode* root = buildBST(preorder, idx, INT_MAX, n);
    /*
              8            
            /   \
           5     10
          / \      \
         1   7      12
    */
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty()){
       TreeNode* node = q.front();
       q.pop();
       cout << node->val << " ";
       if(node->left) q.push(node->left);
       if(node->right) q.push(node->right);
   }
    return 0;
}