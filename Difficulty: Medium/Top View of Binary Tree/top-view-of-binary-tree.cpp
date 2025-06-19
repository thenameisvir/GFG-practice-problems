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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        // Let's do it by level order traversal 
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        
        // yaha hoga apna main logic shuru 
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            Node* node = front.first;
            int level = front.second;
            
            if(mp.find(level)==mp.end()){
                mp[level] = node->data;
            }
            
            if(node->left) q.push({node->left,level-1});
            if(node->right) q.push({node->right,level+1});
            
        }
        
        vector<int>ans;
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};