/*
class Node {
  public:
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
    Node* parentMapping(Node* root, int target, unordered_map<Node*,Node*>& parentToChild) {
        Node* one = NULL;
        queue<Node*> q;
        q.push(root);
        parentToChild[root] = NULL;

        while(!q.empty()) {
            Node* front = q.front();
            q.pop(); // missing pop

            if(front->data == target) {
                one = front;
            }
            if(front->left) {
                parentToChild[front->left] = front;
                q.push(front->left);
            }
            if(front->right) {
                parentToChild[front->right] = front;
                q.push(front->right);
            }
        }

        return one;
    }

    void burnItDown(unordered_map<Node*, Node*>& parentToChild, Node* find, int& ans) {
        unordered_map<Node*, bool> mp;
        queue<Node*> q;

        mp[find] = true;
        q.push(find);

        while(!q.empty()) {
            int size = q.size();
            bool flag = false; // reset per level

            for(int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                if(front->left && !mp[front->left]) {
                    q.push(front->left);
                    mp[front->left] = true;
                    flag = true;
                }
                if(front->right && !mp[front->right]) {
                    q.push(front->right);
                    mp[front->right] = true;
                    flag = true;
                }
                if(parentToChild[front] && !mp[parentToChild[front]]) {
                    q.push(parentToChild[front]);
                    mp[parentToChild[front]] = true;
                    flag = true;
                }
            }

            if(flag) {
                ans++;
            }
        }
    }

    int minTime(Node* root, int target) {
        int ans = 0;
        unordered_map<Node*, Node*> parentToChild;
        Node* find = parentMapping(root, target, parentToChild);
        burnItDown(parentToChild, find, ans);
        return ans;
    }
};
