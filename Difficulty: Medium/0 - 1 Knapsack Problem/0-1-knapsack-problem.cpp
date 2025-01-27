//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int usingRec(int capacity, vector<int> &val, vector<int> &wt,int index,int n){
        // base case baad me dekhenge abhi hum nhi soch paye ye
        if(index==n-1){
            if(capacity-wt[index]>=0){
                return val[index];
            }
            else{
                return 0;
            }
        }
        if(index>=n) return 0;
        
        // ek case solve karo baki mai dekh lunga  inc/exc
        int inc = 0;
        if(wt[index]<=capacity){
            inc = val[index] + usingRec(capacity-wt[index],val,wt,index+1,n);
        }
        int exc = 0 + usingRec(capacity,val,wt,index+1,n);
        
        return max(inc,exc);
        
        
    }
    int solveUsingMem(int capacity, vector<int> &val, vector<int> &wt,int index,int n,vector<vector<int>>&dp){
        if(index==n-1){
            if(capacity-wt[index]>=0){
                return val[index];
            }
            else{
                return 0;
            }
    }
    
    // return ka dekhte hai kya krna hai
    if(dp[capacity][index]!=-1){
        return dp[capacity][index];
    }
    
    
    // recursion baba ki jai
    
    int inc = 0;
        if(wt[index]<=capacity){
            inc = val[index] + solveUsingMem(capacity-wt[index],val,wt,index+1,n,dp);
        }
        int exc = 0 + solveUsingMem(capacity,val,wt,index+1,n,dp);
        
        dp[capacity][index] =  max(inc,exc); 
        
        return dp[capacity][index];
        
        
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // not much different but it's okay
        int n = wt.size();
        vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
        int ans = solveUsingMem(capacity,val,wt,0,wt.size(),dp);
        return ans;
        
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