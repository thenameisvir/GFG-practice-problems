//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
    void ordering(stack<int>&st,int src,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj){
        vis[src] = true;
        
        for(auto i:adj[src]){
            if(!vis[i]){
                ordering(st,i,vis,adj);
            }
        }
        
        st.push(src);
    }
    void dfs2(int src,unordered_map<int,bool>&vis2,unordered_map<int,list<int>>&adj2){

    vis2[src] = true;
    for(auto i:adj2[src]){
        if(!vis2[i]){
            dfs2(i,vis2,adj2);
        }
    }

        
    }
    int kosaraju(vector<vector<int>> &arr) {
        unordered_map<int,list<int>>adj;
        for(int i = 0;i<arr.size();i++){
            for(int j = 0;j<arr[i].size();j++){
                int u = i;
                int v = arr[i][j];
                adj[u].push_back(v);
            }
        }
        
        // adj list bana di hai ab ordering nikalenge
        stack<int>st;
        unordered_map<int,bool>vis;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ordering(st,i,vis,adj);
            }
        }
        
        // yaha tak ordering nikal chuki hai 
        unordered_map<int,list<int>>adj2;
        // ab jo hai nodes ko reverse karna padega
        for(auto i:adj){
    for(auto j:i.second){
        adj2[j].push_back(i.first);
    }
}

        
        // yaha tak hum edges bhi reverse kar chuke hai ab normal dfs 
        unordered_map<int,bool>vis2;
        // yaha pr hum stack ki ordering se chalenge
        int count = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!vis2[top]){
                dfs2(top,vis2,adj2);
                count++;
            }
        }
        
        return count;
        
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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends