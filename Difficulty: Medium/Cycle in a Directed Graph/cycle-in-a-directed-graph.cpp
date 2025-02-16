//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // sabse pehle apan
        queue<int>q;
        unordered_map<int,int>in;
        vector<int>v;
        
        // sabse pehle indegree daal do 
        for(auto i:adj){
            for(auto j:i){
                in[j]++;
            }
        }
        
        // now push all the indegree which have 0 in the queue
        for(int i=0;i<adj.size();i++){
            if(in[i]==0) q.push(i);
        }
        // now continue with the same logic
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            v.push_back(front);
            for(auto i:adj[front]){
                // yaha 2 cheesein krenge apan 
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }
        
        return adj.size()!=v.size();
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