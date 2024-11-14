//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    void reverse(queue<int>&q, int k){
        int n2 = k;
        stack<int>st;
        
        while(k){
            int f = q.front();
            q.pop();
            st.push(f);
            k--;
        }
        
        while(!st.empty()){
            int t = st.top();
            q.push(t);
            st.pop();
        }
        
        int n1 = q.size();
        
        int op = n1-n2;
        
        while(op){
            int f = q.front();
            q.pop();
            q.push(f);
            op--;
        }
        
        
    }
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        reverse(q, k);
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends