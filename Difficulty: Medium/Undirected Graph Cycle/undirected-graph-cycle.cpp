//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int src,unordered_map<int,bool>&vis,unordered_map<int,int>&parent,queue<int>&q,vector<vector<int>>& adj){
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i:adj[front]){
               if(!vis[i]){
                vis[i] = true;
                parent[i] = front;
                q.push(i);
               }
               else if(vis[i] == true && parent[front]!=i){
                   return true;
               }
            }
        }
        
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        unordered_map<int,bool>vis;
        unordered_map<int,int>parent;
        queue<int>q;
        
        // pehla node process ker lete hai
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                bool ans = check(i,vis,parent,q,adj);
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