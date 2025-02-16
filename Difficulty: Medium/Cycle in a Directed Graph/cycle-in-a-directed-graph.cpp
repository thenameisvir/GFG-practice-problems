//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(int src,vector<vector<int>> &adj,unordered_map<int,bool>&vis,unordered_map<int,bool>&track){
        vis[src] = true;
        track[src] = true;
        
        for(auto i:adj[src]){
            if(!vis[i]){
                bool ans = check(i,adj,vis,track);
                if(ans) return true;
            }
            else if(vis[i]==1 && track[i]==1) return true;
        }
        
        track[src] = false;
        
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj) {
        unordered_map<int,bool>vis;
        // unordered_map<int,bool>track;
        unordered_map<int,bool>track;
        // unor
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                bool ans = check(i,adj,vis,track);
                if(ans) return true;
            }
        }
        
        return false;
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