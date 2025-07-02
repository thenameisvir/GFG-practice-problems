/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans;
        Node* succ = NULL;
        Node* pred = NULL;
        
        Node* temp1 = root;
        Node* temp2 = root;
        
        // Finding successor
        while (temp1) {
            if (temp1->data > key) {
                succ = temp1;
                temp1 = temp1->left;
            } else {
                temp1 = temp1->right;
            }
        }
        
        // Finding predecessor
        while (temp2) {
            if (temp2->data < key) {
                pred = temp2;
                temp2 = temp2->right;
            } else {
                temp2 = temp2->left;
            }
        }
        
        ans.push_back(pred);  // pred can be NULL if no predecessor
        ans.push_back(succ);  // succ can be NULL if no successor
        return ans;
    }
};













