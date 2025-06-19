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
    vector<int> bottomView(Node *root) {
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        vector<int>ans;
        while(!q.empty()){
            auto front = q.front();
            Node* node = front.first;
            int level = front.second;
            q.pop();
            
            if(mp.find(level)==mp.end()){
                mp[level] = node->data;
            }
            else{
                mp[level] = node->data;
            }
            
            
            if(node->left) q.push({node->left,level-1});
            if(node->right) q.push({node->right,level+1});
            
            
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};