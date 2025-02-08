//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // ek unordered map chaiye
       vector<int> v;
    unordered_map<int, bool> vis;
    queue<int> q;

    int src = 0; // Start from node 0 (assuming connected graph)
    q.push(src);
    vis[src] = true;

    while (!q.empty()) {
        int front = q.front();
        v.push_back(front);
        q.pop();

        for (auto i : adj[front]) {
            if (!vis[i]) {  // No need for i.first, since i is an int
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return v;
    
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends