//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int usingRec(int capacity, vector<int> &val, vector<int> &wt,int i,int n){
        // base case baad me likhenge 
        if(i>=n) return 0;
        
        // ek case process karo baki ka baad me dekh lenge
        int inc = 0;
        if(capacity>=wt[i]){
            inc = val[i] + usingRec(capacity-wt[i],val,wt,i+1,n);
        }
        
        int exc = 0 + usingRec(capacity,val,wt,i+1,n);
        
        return max(inc,exc);
    }
    
    
    int usingMemo(int capacity, vector<int> &val, vector<int> &wt,int i,int n,vector<vector<int>>&dp){
        if(i==n-1){
            if(capacity>=wt[i]){
                return val[i]; // yaha mai value return kar dunga 
            }
            else{
                return 0;
            }
        }
        
        // dp me store kar lenge aram se
        if(dp[capacity][i]!=-1){
            return dp[capacity][i];
        }
        
        // ek case solve karo baki baad me dekh lenge
        int inc = 0;
        if(capacity>=wt[i]){
            inc = val[i] + usingMemo(capacity-wt[i],val,wt,i+1,n,dp);
        }
        
        int exc = 0 + usingMemo(capacity,val,wt,i+1,n,dp);
        
        dp[capacity][i] = max(inc,exc);
        
        return dp[capacity][i];
    
        
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
         vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
        int ans = usingMemo(capacity,val,wt,0,n,dp); return ans;
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends