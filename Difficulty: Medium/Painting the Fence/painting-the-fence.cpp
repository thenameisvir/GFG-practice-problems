//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long solveUsingRec(int n,int k){
if(n==1) return k;
if(n==2) return k + k*(k-1);
        // ek case solve karo baki recursion dekh lega:
long long ans = (k-1)*(solveUsingRec(n-1,k)+solveUsingRec(n-2,k));

                
return ans;
         
    }
    
    long long usingMemo(int n,int k,vector<int>&dp){
        if(n==1) return k;
        if(n==2) return k + k*(k-1);
    
    if(dp[n]!=-1){
        return dp[n];
    }
    
    long long ans = (k-1)*(usingMemo(n-1,k,dp)+usingMemo(n-2,k,dp));
    
    dp[n] = ans;
    return dp[n];

    }
    
    long long countWays(int n, int k) {
        vector<int>dp(n+1,-1);
        long long ans = usingMemo(n,k,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends