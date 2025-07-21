class Solution {
  public:
    int solve(vector<int>& arr,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=arr.size()){
            return 0;
        }
        
        if(dp[curr][prev+1]!=0){
            return dp[curr][prev+1];
        }
        
        int inc = 0;
        if(prev==-1 || arr[curr]>arr[prev]){
            inc = 1 + solve(arr,curr+1,curr,dp);
        }
        
        int exc = 0 + solve(arr,curr+1,prev,dp);
        
        return dp[curr][prev+1] = max(inc,exc);
        
    }
    // int tab()
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return solve(arr,0,-1,dp);
    }
};