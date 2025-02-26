//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int count = 0;
    // Function to find minimum time required to rot all oranges.
    bool isSafe(int x,int y,map<pair<int,int>,bool>&vis,vector<vector<int>>& arr){
        if(x>=0 && x<arr.size() && y>=0 && y<arr[0].size() && !vis[{x,y}] && arr[x][y]==1){
            return true;
        }
        
        return false;
    }
    void bfs(map<pair<int,int>,bool>&vis,vector<vector<int>>& arr,queue<pair<int,int>>&q){
         int dx[] = {-1,0,1,0};
         int dy[] = {0,1,0,-1};
         
         // mera logic hi queue pr depend kar raha hai 
         while(!q.empty()){
             int size = q.size();
             bool flag = false;
             
             while(size--){
                 auto topPair = q.front();
                 q.pop();
                 int tempx = topPair.first;
                 int tempy = topPair.second;
                 
                 for(int i=0;i<4;i++){
                     int newx = tempx + dx[i];
                     int newy = tempy + dy[i];
                     
                     if(isSafe(newx,newy,vis,arr)){
                         flag = true;
                         vis[{newx,newy}] = true;
                         q.push({newx,newy});
                         arr[newx][newy] = 2;
                     }
                 }
             }
             
             if(flag) count++;
         }
         
         
    }
    int orangesRotting(vector<vector<int>>& arr) {
        
        map<pair<int,int>,bool>vis;
        queue<pair<int,int>>q;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==2){
                    vis[{i,j}] = true;
                    q.push({i,j});
                }
            }
        }
        
        // yaha tak apna initial case zindabaad hai 
        bfs(vis,arr,q);
        
        
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1){
                    return -1;
                }
            }
        }
        
        
        return count;
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends