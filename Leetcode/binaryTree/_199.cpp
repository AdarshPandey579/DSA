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

vector<int> ans;
map<int,int> mp;
void rightSideView(TreeNode* root, int i){
    if(root == NULL) return ;
    if(mp.find(i) == mp.end()){
        mp[i]++;
        ans.push_back(root->val);
    }
    rightSideView(root->right, i+1);
    rightSideView(root->left, i+1);
}

int main(){
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    /*
              1
            /   \
           2     3
          / \     \
         4   5     6
    */

    rightSideView(root,0);
    for(auto i: ans) cout<<i<<" ";
    return 0;
}