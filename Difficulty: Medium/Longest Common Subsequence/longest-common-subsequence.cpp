//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    int usingMemo(string &text1, string &text2,int i,int j,vector<vector<int>>&dp){
        if(i>=text1.length()){
            return 0;
        }
        if(j>=text2.length()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 0;
        if(text1[i]==text2[j]){
            ans = 1+ usingMemo(text1,text2,i+1,j+1,dp); // ye sb baad me dekhenge
        }
        else{
            ans = max(usingMemo(text1,text2,i+1,j,dp),usingMemo(text1,text2,i,j+1,dp));
        }

        dp[i][j] = ans;

        return dp[i][j];



    }
    int lcs(string& text1, string& text2) {
       int i = 0;
        int j = 0;
    vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size(),-1));
        int ans = usingMemo(text1,text2,i,j,dp);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends