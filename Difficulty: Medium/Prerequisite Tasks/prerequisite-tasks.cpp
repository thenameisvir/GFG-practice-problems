//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& arr) {
        unordered_map<int,list<int>>adj;
        for(auto i:arr){
            int u = i.first;
            int v = i.second;
            
            adj[v].push_back(u);
        }
        
        // ab yaha se apna topological sort ka code hoga chalu
        unordered_map<int,int>in; // isme indegree store hoga
        queue<int>q;
        vector<int>v;
        // ab store karo
        for(auto i:adj){
            for(auto j:i.second){
                in[j]++;
            }
        }
        
        // ab 0 degree walo ko add kardo queue me 
        for(int i=0;i<N;i++){
            if(in[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            v.push_back(1);
            
            for(auto i:adj[front]){
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }
        
        
        return v.size()==N;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends