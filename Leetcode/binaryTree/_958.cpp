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

bool isCompleteTree(TreeNode* root) {
    bool complete=true;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* f = q.front();
        q.pop();
        if(f==NULL) complete=false;
        else{
            if(!complete) return false;
            q.push(f->left);
            q.push(f->right);
        }
    }
    return true;
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

    cout<<isCompleteTree(root)<<endl;
    return 0;
}