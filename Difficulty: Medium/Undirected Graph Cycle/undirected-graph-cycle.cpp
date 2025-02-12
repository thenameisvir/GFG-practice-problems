//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool ansde(int src,unordered_map<int,bool>&vis,int parent,vector<vector<int>>& adj){
         vis[src] = true;
         
         for(auto i:adj[src]){
             if(!vis[i]){
                 bool ans = ansde(i,vis,src,adj);
                 if(ans) return true;
             }
             else if(vis[i]==true && i!=parent) return true;
         }
         
         
         
         return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        unordered_map<int,bool>vis;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int parent = -1;
                bool ans = ansde(i,vis,parent,adj);
            if(ans) return true;
            }
        }
        
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends