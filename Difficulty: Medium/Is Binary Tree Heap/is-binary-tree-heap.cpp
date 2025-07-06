// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class Solution {
  public:
    // Check if tree is CBT
    bool isCBT(Node* root) {
        if (!root) return true;
        
        queue<Node*> q;
        q.push(root);
        bool nullSeen = false;
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if (curr->left) {
                if (nullSeen) return false;
                q.push(curr->left);
            } else {
                nullSeen = true;
            }
            
            if (curr->right) {
                if (nullSeen) return false;
                q.push(curr->right);
            } else {
                nullSeen = true;
            }
        }
        return true;
    }

    // Check heap property (Max Heap)
    bool isMaxHeap(Node* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;

        if (root->left && root->data < root->left->data) return false;
        if (root->right && root->data < root->right->data) return false;

        return isMaxHeap(root->left) && isMaxHeap(root->right);
    }

    bool isHeap(Node* root) {
        return isCBT(root) && isMaxHeap(root);
    }
};
