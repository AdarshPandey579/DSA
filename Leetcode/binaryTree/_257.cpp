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

vector<string> ans;
void path(TreeNode* root, string tmp){
    if(root==NULL) return ;
    tmp.append(to_string(root->val));
    if(root->left==NULL && root->right==NULL){
        ans.push_back(tmp);
        return;
    }
    tmp+="->";
    path(root->left, tmp);
    path(root->right, tmp);
    
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    /*
              4            
            /   \
           2     7
          / \
         1   3
    */

    path(root, "");
    for(auto v: ans){
        cout<<v<<endl;
    }

    return 0;
}