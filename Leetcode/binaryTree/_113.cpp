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

vector<vector<int>> ans;
void func(TreeNode* root, int targetSum, vector<int>& tmp){
    if(root==NULL) return;
    targetSum-=root->val;
    tmp.push_back(root->val);
    if(root->left==NULL && root->right==NULL) {
        if(targetSum==0) ans.push_back(tmp);
        tmp.pop_back();
        return;
    }
    func(root->left, targetSum, tmp);
    func(root->right, targetSum, tmp);
    tmp.pop_back();
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);

    /*
              1
            /   \
           2     5
          / \   / \
         4   5 1   7
    */

    int targetSum = 7;

    vector<int> tmp;
    func(root, targetSum, tmp);
    for(auto v: ans){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}