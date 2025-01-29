//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int usingTab(string a, string b){
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
    // fill something into the dp according to the base cases 
    // here we took the size of the 2D matrix increasd because we need to attain indexes in tabulation
    // so to not get out of bound this is mandatory
    for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
        int ans = 0;
        // if my both of the char are matching
        if(a[i]==b[j]){
            ans = 1 + dp[i+1][j+1];
        }
        else{
            ans = 0 + max(dp[i+1][j],dp[i][j+1]);
        }
        dp[i][j] = ans;
        }


    }

    return dp[0][0];


    }
    int longestPalinSubseq(string &s) {
       string a = s;
        string b = s;
        reverse(b.begin(),b.end());
        int ans = usingTab(a,b); return ans;
    }
};

//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends