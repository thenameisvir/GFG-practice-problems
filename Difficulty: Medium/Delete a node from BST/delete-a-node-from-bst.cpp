class Solution {
  public:
    Node* maximum(Node* root){
        if(!root){
            return NULL;
        }
        else{
            while(root->right){
                root = root->right;
            }
        }
        
        return root;
        // one catch is here that is we need not to pass the node by ref
    }
    Node *deleteNode(Node *root, int X) {
        if(!root){
            return NULL;
        }
        
        if(root->data==X){
            // case 1
            if(!root->left && !root->right){
                delete root;
                return NULL; // easy peasy
            }
            else if(!root->left && root->right){
                Node* child = root->right;
                delete root;
                return child;
            }
            else if(!root->right && root->left){
                Node* child = root->left;
                delete root;
                return child;
            }
            else{
                // main case
                Node* maxi = maximum(root->left);
                root->data = maxi->data;
                
                // now our main work starts
                root->left = deleteNode(root->left,maxi->data);
                
                return root;
            }
        }
        else if(root->data>X){
            root->left = deleteNode(root->left,X);
        }
        else{
            root->right = deleteNode(root->right,X);
        }
        
        return root;
    }
};