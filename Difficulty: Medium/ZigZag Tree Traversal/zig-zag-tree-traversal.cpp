/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
       vector<int>vir;
       if(!root) return vir;
       
       queue<Node*>q;
       q.push(root);
       bool flag = true;
       while(!q.empty()){
           
           int size = q.size();
           vector<int>temp(size);
           
           for(int i=0;i<size;i++){
               Node* front = q.front(); q.pop();
               int index = flag ? i : size - i - 1;
               temp[index] = front->data;
               
               // iske baad left aur right me simple call laga do
               if(front->left) q.push(front->left);
               if(front->right) q.push(front->right);
               
           }
           
           // yaha main logic sirf flag ka hai 
           flag = !flag;
           
           for(int i=0;i<size;i++){
               int num = temp[i];
               vir.push_back(num);
           }
           
           
       }
       
       return vir;
    }
};