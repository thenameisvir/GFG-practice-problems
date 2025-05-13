//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& coins, int sum,int i,vector<vector<int>>&dp){
        if(i>=coins.size() || sum<0) return 0;
        if(sum==0) return 1;
        
        if(dp[sum][i]!=-1){
            return dp[sum][i];
        }
        
        int inc = solve(coins,sum-coins[i],i,dp);
        int exc = solve(coins,sum,i+1,dp);
        
        return dp[sum][i] = inc+exc;
    }
    int count(vector<int>& coins, int sum) {
        vector<vector<int>>dp(sum+1,vector<int>(coins.size()+1,-1));
        int ans = solve(coins,sum,0,dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends