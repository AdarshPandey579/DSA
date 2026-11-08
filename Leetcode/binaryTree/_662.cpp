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

int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, unsigned long long>> q;
    unsigned long long ans=0;
    q.push({root, 0});
    while(!q.empty()){
        unsigned long long stIdx = q.front().second;
        unsigned long long endIdx = q.back().second;
        ans=max(ans, endIdx-stIdx+1);
        int n = q.size();
        while(n--){
            pair<TreeNode*, unsigned long long> top = q.front();
            q.pop();
            if(top.first->left) q.push({top.first->left, top.second*2 +1});
            if(top.first->right) q.push({top.first->right, top.second*2 +2});
        }
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    /*
              1            
            /   \
           3     2
          / \     \
         5   3     9
*/

    cout << widthOfBinaryTree(root);
    return 0;
}