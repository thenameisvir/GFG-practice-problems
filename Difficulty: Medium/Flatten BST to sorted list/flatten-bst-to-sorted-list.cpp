// User function Template for C++

/* Node of the binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, Node* &head) {
        if (!root) return;

        // Reverse Inorder Traversal
        solve(root->right, head);

        root->right = head;
        if (head) head->left = root;

        head = root;

        solve(root->left, head);
    }

    void solve1(Node* head) {
        Node* temp = head;

        while (temp) {
            temp->left = NULL;
            temp = temp->right;
        }
    }

    Node* flattenBST(Node* root) {
        Node* head = NULL;
        solve(root, head);
        solve1(head);
        return head;
    }
};
