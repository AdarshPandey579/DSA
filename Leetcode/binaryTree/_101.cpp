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

bool isSymmetric(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    if(p->val != q->val) return false;
    bool Left = isSymmetric(p->left, q->right);
    bool Right = isSymmetric(p->right, q->left);
    return Left && Right ;
}

int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    /*
              1            
            /   \
           2     3
*/

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(3);
    q->right = new TreeNode(2);
    /*
              1            
            /   \
           3     2
*/

    cout << isSymmetric(p,q);
    return 0;
}