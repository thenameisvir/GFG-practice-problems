/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    void solve(Node* root, vector<int>& leaves){
        if(!root) return;
        if(!root->left && !root->right){
            leaves.push_back(root->data);
            return;
        }
        solve(root->left, leaves);
        solve(root->right, leaves);
    }

    bool search(Node* root, int val){
        if(!root) return false;
        if(root->data == val) return true;
        if(val < root->data) return search(root->left, val);
        else return search(root->right, val);
    }

    bool isDeadEnd(Node *root) {
        vector<int> leaves;
        solve(root, leaves);
        
        for(int val : leaves){
            if(val == 1){
                if(search(root, 2)) return true;
                continue; // to avoid checking val-1 = 0
            }
            if(search(root, val - 1) && search(root, val + 1)){
                return true;
            }
        }
        
        return false;
    }
};



