//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void solve(vector<int> &arr,int target,vector<vector<int>>&v,vector<int>&ans,int j){
        // base case toh ratt jana chaiye
        if(target==0){
            v.push_back(ans);
            return;
        }
        
        // bas ab kch mt kar if for loop likh raha hai toh 
        for(int i = j;i<arr.size();i++){
            // sabse pehle check karo kahi jo element hai vo same toh nahi hai
            if( i > j && arr[i]==arr[i-1]) continue; // continue kardo
            // madhur isme tu indexing ka logic bhul gaya tha vo bhi dekh lena 
            // ab break wali condition check kar 
            if(target<arr[i]) break; // seedha seedha logic hai zada dimag marne ki need na
            
            ans.push_back(arr[i]);
            solve(arr,target-arr[i],v,ans,i+1); // i+1 coz no duplicates
            ans.pop_back();
            
            
        }
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        vector<vector<int>>v;
        vector<int>ans;
        sort(arr.begin(),arr.end());
        solve(arr,target,v,ans,0);
        
        return v;
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
        vector<vector<int>> ans = ob.uniqueCombinations(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends