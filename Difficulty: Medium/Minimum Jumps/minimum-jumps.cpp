//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, vector<int>& arr, vector<int>& dp) {
    int n = arr.size();
    if (i >= n - 1) return 0; // Reached or passed the end
    if (arr[i] == 0) return 1e9; // Can't move ahead
    if (dp[i] != -1) return dp[i];

    int minJumps = 1e9;
    for (int j = 1; j <= arr[i]; j++) {
        minJumps = min(minJumps, 1 + solve(i + j, arr, dp));
    }

    return dp[i] = minJumps;
}

int minJumps(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, -1);
    int ans = solve(0, arr, dp);
    return (ans >= 1e9) ? -1 : ans;
}

};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends