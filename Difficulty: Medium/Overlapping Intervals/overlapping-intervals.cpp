//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        // first step pf sorting done
        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(arr[i]); // empty hai toh sedha push kar dia
            }
            else{
                vector<int>&v = ans.back();
                int y = v[1];
                
                // overlapping ho rahi hai ya nahi
                if(arr[i][0]<=y){
                    v[1] = max(y,arr[i][1]);
                }
                else{
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends