//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr,int s,int e,vector<int>&dp){
        if(s>e) return 0;
        
        if(dp[s]!=-1){
            return dp[s];
        }
        
        int inc = arr[s] + solve(arr,s+2,e,dp);
        int exc = 0 + solve(arr,s+1,e,dp);
        
        
        dp[s] = max(inc,exc);
        return dp[s];
    }
    int maxValue(vector<int>& arr) {
        vector<int>dp1(arr.size()+1,-1);
        vector<int>dp2(arr.size()+1,-1);
        
        int ans1 = solve(arr,0,arr.size()-2,dp1);
        int ans2 = solve(arr,1,arr.size()-1,dp2);
        return max(ans1,ans2);
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends