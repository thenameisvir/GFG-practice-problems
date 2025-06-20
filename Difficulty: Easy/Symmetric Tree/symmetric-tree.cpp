/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    void check1(Node* root,vector<int>&v1){
        if(!root){
            v1.push_back(-1);
            return;
        }

        v1.push_back(root->data);
        check1(root->left,v1);
        check1(root->right,v1);
    }
    void check2(Node* root,vector<int>&v2)
    {
        if(!root){
            v2.push_back(-1);
            return;
        }

        v2.push_back(root->data);
        check2(root->right,v2);
        check2(root->left,v2);
    }
    bool isSymmetric(Node* root) {
       if(!root) return true;
        vector<int>v1;
        vector<int>v2;
        check1(root->left,v1);
        check2(root->right,v2);

        return v1==v2;
        
    }
};