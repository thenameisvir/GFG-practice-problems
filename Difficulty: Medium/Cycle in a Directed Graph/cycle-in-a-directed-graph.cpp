//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        unordered_map<int,int>in;
        queue<int>q;
        for(auto i:adj){
            for(auto j:i){
                in[j]++;
            }
        }
        
        for(int i=0;i<adj.size();i++){
            if(in[i]==0) q.push(i);
        }
        
        // ab apna kaam karo
        vector<int>v;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            v.push_back(1);
            for(auto i:adj[front]){
                // 2 cheesein check karo 
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }
        
        return v.size()!=adj.size();
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends