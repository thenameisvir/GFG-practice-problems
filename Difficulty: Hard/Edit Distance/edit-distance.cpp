//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int usingMemo(string s1, string s2,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.length()){
            return s2.length()-j;
        }
        if(j>=s2.length()){
            return s1.length()-i;
        }
        
        // do store in dp vector
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        
        int ans = 0;
        if(s1[i]==s2[j]){
            ans = 0 + usingMemo(s1,s2,i+1,j+1,dp);
        }
        else{
            // here we will be tackling three cases insert replace delete
            int replace = 1 + usingMemo(s1,s2,i+1,j+1,dp);
            int insert = 1 + usingMemo(s1,s2,i+1,j,dp);
            int removee = 1 + usingMemo(s1,s2,i,j+1,dp);
            
            ans = min(removee,min(replace,insert));
        }
        
        dp[i][j] = ans;
        return dp[i][j];
    }
    int tabulation(string& s1, string& s2){
        // put in the vector according to the base case
     vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
     return -1;
    }
    int editDistance(string& s1, string& s2) {
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
        int ans = usingMemo(s1,s2,i,j,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends