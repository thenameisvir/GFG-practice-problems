//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int usingMemo(vector<int>& arr,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=arr.size()) return 0;
        // base case is done , now store it into a dp
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1]; // because prev is at -1 and it won't exist
        }
        
        
        // now solve one case and rest will be done by recursion
        int inc = 0;
        if(prev==-1 || arr[curr]>arr[prev]){
            inc = 1 + usingMemo(arr,curr+1,curr,dp);
        }
        int exc = 0 + usingMemo(arr,curr+1,prev,dp);
        
        dp[curr][prev+1] = max(inc,exc);
        return dp[curr][prev+1];
    }
    int lis(vector<int>& arr) {
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        int ans = usingMemo(arr,0,-1,dp); return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/chatIcon-1653561581.svg