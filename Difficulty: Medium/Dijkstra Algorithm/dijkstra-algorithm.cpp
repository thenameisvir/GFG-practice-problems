//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    vector<int> okay(vector<vector<pair<int, int>>> &adj, int src){
        int n = adj.size();
        vector<int>v(n+1,INT_MAX);
        set<pair<int,int>>st;
        st.insert({0,src});
        v[src] = 0;
        
        while(!st.empty()){
            auto topi = st.begin();
            pair<int,int>lodu = *topi;
            int topnode = lodu.second;
            int topdist = lodu.first;
            
            st.erase(lodu);
            
            // neighbours me jao
            for(auto nbr : adj[topnode]){
                int nbrnode = nbr.first;
                int nbrdist = nbr.second;
                
                // if condition me mar mat jana
                if(v[topnode] + nbrdist<v[nbrnode]){
                    int store = v[nbrnode];
                    
                    v[nbrnode] = v[topnode] + nbrdist;
                    
                    // ab check karo isko
                    auto prev = st.find({store,nbrnode});
                    
                    if(prev!=st.end()){
                        st.erase(prev);
                    }
                    
                    st.insert({v[nbrnode],nbrnode});
                }
            }
        }
        
        for(int i=0;i<v.size();i++){
            if(v[i]==INT_MAX){
                v[i] = -1;
            }
        }
        
        return v;
        
        
    }
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
       vector<int>ans = okay(adj,src);
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends