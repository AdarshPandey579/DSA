#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int sum(Node *root){
    if(root==NULL) return 0;
    int Left = sum(root->left);
    int Right = sum(root->right);
    int curr = root->data;
    root->data=Left+Right;
    return curr+root->data;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    /*
                10                    
             /     \
            -2      6   
           / \     / \
          8   -4   7   5
    */

    sum(root);

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    return 0;
}