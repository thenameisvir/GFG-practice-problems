/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* &root){
        if(!root){
            return 0;
        }
        
        if(!root->left && !root->right){
            int num = root->data;
            root->data = 0;
            return num;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        int temp = root->data;
        root->data = left + right;
        
        return temp + left + right;
    }
    void toSumTree(Node *root) {
        int ans = solve(root);
        // return root;
    }
};