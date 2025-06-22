// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    
    pair<int,int>IncludeExclude(Node* root){
        if(!root){
            return {0,0};
        }
        
        auto lsum = IncludeExclude(root->left);
        auto rsum = IncludeExclude(root->right);
        
        int inc = max(lsum.first,lsum.second) + max(rsum.first,rsum.second);
        int exc = root->data + lsum.first + rsum.first;
        
        return {inc,exc};
    }
    
    int getMaxSum(Node *root) {
        
        auto ans = IncludeExclude(root);
        return max(ans.first,ans.second);
            
        }
};


