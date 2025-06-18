/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        queue<Node*>q;
        q.push(root);
        vector<int>vir;
        if(!root) return vir;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i=0;i<size;i++){
                if(!flag){
                    int element = q.front()->data;
                    vir.push_back(element);
                    flag = true;
                }
                
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                
                q.pop();
            }
        }
        
        return vir;
    }
};