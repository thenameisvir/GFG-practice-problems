/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:
    int ans = 0;

    int h(Node* root) {
        if (!root) {
            return 0;
        }

        int left = h(root->left);
        int right = h(root->right);

        return 1 + max(left, right); // ✔️ correct height logic
    }

    void solve(Node* root, int height, int temp) {
        if (!root && height != 0) {
            return;
        }

        if (!root && height == 0) {
            ans = max(ans, temp);
            return;
        }

        // fix: use root not "rot", and avoid temp += root->data in call
        solve(root->left, height - 1, temp + root->data);
        solve(root->right, height - 1, temp + root->data);
    }

    int sumOfLongRootToLeafPath(Node* root) {
        int height = h(root); // ✔️ get max height
        solve(root, height, 0);
        return ans; // ✔️ don't forget to return the answer
    }
};
