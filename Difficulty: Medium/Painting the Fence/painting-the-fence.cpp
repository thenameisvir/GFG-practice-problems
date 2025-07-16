class Solution {
  public:
    int solve(int n,int k,vector<int>&dp){
        if(n==1) return k;
        if(n==2) return k+(k*(k-1)); // very important observation
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] =  (k-1)*(solve(n-1,k,dp) + solve(n-2,k,dp));
    }
    
    int tab(int n,int k){
     
     vector<int>dp(n+1,-1);
     dp[1] = k;
     dp[2] = k+(k*(k-1));
     
     for(int i=3;i<=n;i++){
         dp[i] = (k-1)*(dp[i-1] + dp[i-2]);
     }
     
     return dp[n];
     
        
    }
    int space(int n, int k){
        if(n==1) return k;
        if(n==2) return k+(k*(k-1));
        int prev = k;
        int curr = k+(k*(k-1));
        
        for(int i=3;i<=n;i++){
            int temp = (k-1)*(prev + curr);
            prev = curr;
            curr = temp;
        }
        
        return curr;
        
    } 
    int countWays(int n, int k) {
        vector<int>dp(n+1,-1);
        return space(n,k);
    }
};