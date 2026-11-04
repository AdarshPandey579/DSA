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

pair<TreeNode*, int> lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL) return {root, 0};
    int head = 0;
    if(root->val == p->val) head++;
    if(root->val == q->val) head++;
    pair<TreeNode*, int> p1 = lowestCommonAncestor(root->left, p, q);
    pair<TreeNode*, int> p2 = lowestCommonAncestor(root->right, p, q);
    if(p1.second==2) return p1;
    if(p2.second==2) return p2;
    if(p1.second+p2.second==2) return {root,2};
    return {root, p1.second+p2.second+head};
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    TreeNode* p = new TreeNode(4);
    TreeNode* q = new TreeNode(3);
    // TreeNode* q = new TreeNode(5);

    pair<TreeNode*, int> result = lowestCommonAncestor(root, p, q);
    cout << result.first->val << endl;

    return 0;
}