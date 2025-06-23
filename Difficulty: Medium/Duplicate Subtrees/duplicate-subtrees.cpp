class Solution {
  public:
    unordered_map<string,int>mp;
    vector<Node*>vir;
    string solve(Node* root){
        if(!root) return "N";
        
        // ab check karo bilkul vaise hi jaise number me kia tha
        string curr = to_string(root->data);
        string left = solve(root->left);
        string right = solve(root->right);
        
        // yaha tak apna ans build ho chuka hoga 
        string final = curr + "," + left + "," + right;
        
        if(mp.find(final)!=mp.end()){
            if(mp[final]==1){
                vir.push_back(root); // kyuki humko uski bas root return karni hai
                mp[final]++;
            }
        }
        else{
            mp[final] = 1; // entry bana do hai nahi toh
        }
        
        
        return final;
    }
    vector<Node*> printAllDups(Node* root) {
       solve(root);
       return vir;
    }
};