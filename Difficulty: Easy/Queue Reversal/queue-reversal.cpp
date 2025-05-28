// function Template for C++

class Solution {
  public:
    void ok(queue<int> &q){
        stack<int>st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
    }
    queue<int> reverseQueue(queue<int> &q) {
        ok(q);
        return q;
    }
};