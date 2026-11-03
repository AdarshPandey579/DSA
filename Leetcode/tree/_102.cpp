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

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty()){
        vector<int> tmp;
        int nodes = q.size();
        while(nodes>0){
            TreeNode* node = q.front();
            q.pop();
            tmp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            nodes--;
        }
        ans.push_back(tmp);
    }
    return ans;
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

    vector<vector<int>> ans = levelOrder(root);
    for(auto v: ans){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }


    return 0;
}