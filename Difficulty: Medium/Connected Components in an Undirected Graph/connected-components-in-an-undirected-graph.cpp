//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


class Solution {
  public:
    void dfs(int src,unordered_map<int,bool>&vis, map<int,list<int>>&adj,vector<int>&v){
        vis[src] = true;
        v.push_back(src);
        
        for(auto i:adj[src]){
            if(!vis[i]){
                dfs(i,vis,adj,v);
            }
        }
        
    }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& arr) {
    
    map<int,list<int>>adj;
    
     for (int i = 0; i < arr.size(); i++) {
            int u = arr[i][0]; // First node of edge
            int v = arr[i][1]; // Second node of edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
    unordered_map<int,bool>vis;
    
    vector<vector<int>>ans;
    
    for(int i=0;i<v;i++){
        if(!vis[i]){
            vector<int>v;
            dfs(i,vis,adj,v);
            
            ans.push_back(v);
        }
    }
    
    for(auto &row : ans){
    sort(row.begin(), row.end());
}
    
    return ans;
    
    
    
    
    
    
    
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends