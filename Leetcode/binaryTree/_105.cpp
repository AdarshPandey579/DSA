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

int idx=0;

TreeNode* cons(vector<int>& P, unordered_map<int,int>& mp, int st, int end) {
    if(st>end) return NULL;
    TreeNode* root = new TreeNode(P[idx]);
    idx++;
    int i=mp[root->val];
    root->left = cons(P, mp, st, i-1);
    root->right = cons(P, mp, i+1, end);
    return root;
}

int main(){
    vector<int> P = {3,9,20,15,7};
    vector<int> I = {9,3,15,20,7};
    unordered_map<int,int> mp;
    for(int i=0;i<I.size();i++) mp[I[i]] = i;
    int n = P.size();
    TreeNode* root = cons(P, mp, 0, n-1);
    queue<TreeNode*> q;

    // level order traversal
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    /*
              3
            /   \
           9     20
                 /  \
                15   7
    */
    return 0;
}