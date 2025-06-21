/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // humesha ke jaise queue ka use karke sab kch karna 
        queue<Node*>q;
        q.push(root);
        vector<int>vir;
        
        while(!q.empty()){
            Node* front = q.front(); q.pop();
            
            while(front){
                vir.push_back(front->data);
                
                if(front->left) q.push(front->left);
                
                front = front->right;
            }
        }
        
        return vir;
        
    }
};