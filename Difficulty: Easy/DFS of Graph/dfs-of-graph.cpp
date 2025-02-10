//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void dfsHelper(int node, vector<vector<int>>& adj, unordered_map<int, bool>& vis, vector<int>& result) {
        vis[node] = true;
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfsHelper(neighbor, adj, vis, result);
            }
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        unordered_map<int, bool> vis;
        vector<int> result;

        for (int i = 0; i < adj.size(); i++) {  // Handle disconnected components
            if (!vis[i]) {
                dfsHelper(i, adj, vis, result);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends