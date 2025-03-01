//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void dfs(int src, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
    {
        vis[src] = true;
        for (auto i : adj[src])
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
            }
        }
    }

    int isBridge(int V, vector<int> arr[], int c, int d)
    {
        unordered_map<int, list<int>> adj;

        // Graph Construction
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                int u = i;
                int v = arr[i][j];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        // Step 1: Count initial connected components
        int count1 = 0;
        unordered_map<int, bool> vis;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
                count1++;
            }
        }

        // Step 2: Remove edge (c, d)
        adj[c].remove(d);
        adj[d].remove(c);

        // Step 3: Count components after removing the edge
        vis.clear();
        int count2 = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
                count2++;
            }
        }

        // If components increased, edge was a bridge
        return (count2 > count1) ? 1 : 0;
    }
};




//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends