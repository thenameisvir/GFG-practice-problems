/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
public:
    bool solve(Node* root, int& k, int node, int& ans) {
        if (!root) return false;

        if (root->data == node) return true;

        // Left or right subtree contains node
        if (solve(root->left, k, node, ans) || solve(root->right, k, node, ans)) {
            if (k > 0) {
                k--;
                if (k == 0) {
                    ans = root->data;
                }
            }
            return true;
        }

        return false;
    }

    int kthAncestor(Node* root, int k, int node) {
        int ans = -1;
        solve(root, k, node, ans);
        return ans;
    }
};


