//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int usingRec(int capacity, vector<int> &val, vector<int> &wt,int i,int n){
        // base case for first in mind
        if(i>=n) return 0;
        
        
        // process one case and leave it all on recursion
        int inc = 0;
        if(capacity>=wt[i]){
            inc = val[i] + usingRec(capacity-wt[i],val,wt,i+1,n);
        }
        int exc = 0 +  usingRec(capacity,val,wt,i+1,n);
        
        return max(inc,exc);
    }
    int memo(int capacity, vector<int> &val, vector<int> &wt,int i,int n,vector<vector<int>>&dp){
        if(i>=n) return 0; // base case as it is
        
        
        // if dp has the answer then return it 
        if(dp[capacity][i]!=-1){
            return dp[capacity][i];
        }
        
        
        int inc = 0;
        if(capacity>=wt[i]){
            inc = val[i] + memo(capacity-wt[i],val,wt,i+1,n,dp);
        }
        int exc = 0 +  memo(capacity,val,wt,i+1,n,dp);
        
        dp[capacity][i] = max(inc,exc);
        return dp[capacity][i];
        
        
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        vector<vector<int>>dp(capacity+1,vector<int>(wt.size(),-1));
        int ans = memo(capacity,val,wt,0,val.size(),dp); return ans;
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