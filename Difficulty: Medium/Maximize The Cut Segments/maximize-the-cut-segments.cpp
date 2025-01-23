//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of cuts.
    int solveUsingMem(int n, int x, int y, int z,vector<int>&dp){
        if(n==0){
            return 0;
        }    
        
        if(n<0){
            return INT_MIN;
        }
        
        if(dp[n]!=INT_MIN){
            return dp[n];
        }
        
    int ans1 = (n >= x) ? 1 + solveUsingMem(n - x, x, y, z, dp) : INT_MIN;
    int ans2 = (n >= y) ? 1 + solveUsingMem(n - y, x, y, z, dp) : INT_MIN;
    int ans3 = (n >= z) ? 1 + solveUsingMem(n - z, x, y, z, dp) : INT_MIN;

    dp[n] = max({ans1, ans2, ans3});
    return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int>dp(n+1,INT_MIN);
        int ans = solveUsingMem(n,x,y,z,dp);
        if(ans<0) return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    // taking testcases
    int t;
    cin >> t;
    while (t--) {
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends