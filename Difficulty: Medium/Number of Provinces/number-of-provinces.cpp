//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int src,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis){
        vis[src] = true;
        
        for(auto i:adj[src]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> arr, int V) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        
        // yaha tak apna map toh tyar hai ekdum
        unordered_map<int,bool>vis;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            if(!vis[i]){
                dfs(i,adj,vis);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends