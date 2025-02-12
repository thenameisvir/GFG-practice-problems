//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int src,unordered_map<int,bool>&vis,unordered_map<int,bool>&track,vector<vector<int>> adj){
        vis[src] = true;
        track[src] = true;
        
        for(auto i:adj[src]){
            if(!vis[i]){
                bool ans = check(i,vis,track,adj);
                if(ans) return true;
            }
            
            if(vis[i]==1 && track[i]==1){
                return true;
            }
            
        }
        
        track[src] = false;
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        unordered_map<int,bool>vis;
        unordered_map<int,bool>track;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans = check(i,vis,track,adj);
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
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends