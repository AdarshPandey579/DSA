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

bool identical(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    if(p->val != q->val) return false;
    bool Left = identical(p->left, q->left);
    bool Right = identical(p->right, q->right);
    return Left && Right ;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root==NULL) return false;
    if(root->val==subRoot->val && identical(root, subRoot)) return true;
    bool Left = isSubtree(root->left, subRoot);
    bool Right = isSubtree(root->right, subRoot);
    return Left||Right;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    /*
              3            
            /   \
           4     5
          / \
         1   2
*/

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);
    /*
              4            
            /   \
           1     2
*/

    cout << isSubtree(root,subRoot);
    return 0;
}