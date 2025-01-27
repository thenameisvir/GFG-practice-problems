//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int usingRec(int n,int k){
        
        // base case ek toh smjh aa rha hai ki
        if(n==1) return k; // kyuki aur koi choice hi nahi hai apne pas
        
        if(n==2) return k+k*(k-1);
        
        // dono base case smjh aagye hain ab ans build karte hai chalo
        
        int ans = (usingRec(n-1,k) + usingRec(n-2,k))*(k-1);
        
        return ans;
        
        
    }
    
    int usingMemo(int n,int k,vector<int>&dp){
        if(n==1) return k;
        
        if(n==2) return k+k*(k-1);
        // copy paste base case as it is
        
        if(dp[n]!=-1) return dp[n];
        
        int ans = (usingMemo(n-1,k,dp) + usingMemo(n-2,k,dp))*(k-1);
        
        dp[n] = ans;
        return dp[n];
    }
    int countWays(int n, int k) {
        
        // int ansOfRec = usingRec(n,k); return ansOfRec;
        vector<int>dp(n+1,-1);
        int ans = usingMemo(n,k,dp); return ans;
        
        
        
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