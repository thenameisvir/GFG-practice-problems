//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool isCycle(vector<vector<int>>& adj) {  // Pass total nodes `n`
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;
    queue<int> q;
    int n = adj.size();

    for (int i = 0; i < n; i++) {  // Check all components
        if (!vis[i]) {
            q.push(i);
            vis[i] = true;
            parent[i] = -1;

            while (!q.empty()) {
                int front = q.front();
                q.pop();

                for (auto neighbor : adj[front]) {
                    if (!vis[neighbor]) {
                        q.push(neighbor);
                        vis[neighbor] = true;
                        parent[neighbor] = front;
                    } 
                    else if (parent[front] != neighbor) {  // Correct condition
                        return true;
                    }
                }
            }
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