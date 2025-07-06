// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    void okay(Node* root,vector<int>&ans){
        // we are storing inorder here
        if(!root){
            return;
        }
        okay(root->left,ans);
        ans.push_back(root->data);
        okay(root->right,ans);
    }
    void solve(Node* root,vector<int>&ans,int &i){
        if(!root){
            return;
        }
        solve(root->left,ans,i);
        solve(root->right,ans,i);
        
        root->data = ans[i];
        i++;
    }
    void convertToMaxHeapUtil(Node* root) {
        vector<int>ans;
        
        okay(root,ans);
        // now till here we have solved the inorder part
        int i =0;
        solve(root,ans,i);
        
        
    }
};
