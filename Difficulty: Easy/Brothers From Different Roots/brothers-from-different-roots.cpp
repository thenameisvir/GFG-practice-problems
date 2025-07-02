/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int>& v){
        if(!root) return;
        solve(root->left, v);
        v.push_back(root->data);
        solve(root->right, v);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        vector<int> temp1, temp2;
        solve(root1, temp1);  // ✅ fix: use root1
        solve(root2, temp2);  // ✅ fix: use root2

        unordered_map<int, bool> mp;
        for(int val : temp1){
            mp[val] = true;
        }

        int count = 0;
        for(int val : temp2){
            int complement = x - val;
            if(mp.find(complement) != mp.end()){
                count++;
            }
        }

        return count;
    }
};
