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
        
    int op1 = INT_MIN;
    int op2 = INT_MIN;
    int op3 = INT_MIN;
    if(n>=x){
        op1 = 0;
        op1 = 1 + solveUsingMem(n-x,x,y,z,dp);
    }
    if(n>=y){
        op2 = 0;
        op2 = 1 + solveUsingMem(n-y,x,y,z,dp);
    }
    if(n>=z){
        op3 = 0;
        op3 = 1 + solveUsingMem(n-z,x,y,z,dp);
    }
    

    dp[n] = max({op1, op2, op3});
    return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int>dp(n+1,INT_MIN);
        int ans = solveUsingMem(n,x,y,z,dp);
        if(ans<0) return 0;
        return ans;
    }
};
