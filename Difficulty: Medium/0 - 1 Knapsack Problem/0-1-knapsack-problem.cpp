//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int W, vector<int> &val, vector<int> &wt, int i, vector<vector<int>> &dp) {
        if(i >= val.size()) return 0;
        if(dp[i][W] != -1) return dp[i][W];

        int inc = 0, exc = 0;
        if(W >= wt[i]) {
            inc = val[i] + solve(W - wt[i], val, wt, i + 1, dp);
        }
        exc = solve(W, val, wt, i + 1, dp);

        return dp[i][W] = max(inc, exc);
    }
    int usingTab(int W, vector<int> &val, vector<int> &wt){
         int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int w = 0; w <= W; w++) {
            int inc = 0, exc = 0;
            if (w >= wt[i]) {
                inc = val[i] + dp[i + 1][w - wt[i]];
            }
            exc = dp[i + 1][w];
            dp[i][w] = max(inc, exc);
        }
    }

    return dp[0][W];
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        return usingTab(W, val, wt);
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
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends