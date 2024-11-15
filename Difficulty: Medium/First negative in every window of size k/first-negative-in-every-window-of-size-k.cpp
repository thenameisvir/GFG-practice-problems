//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
       queue<int> q;
    vector<int> result;

    // Process the first k elements
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            q.push(i);
        }
    }

    // Add the result for the first window
    if (!q.empty()) {
        result.push_back(arr[q.front()]);
    } else {
        result.push_back(0); // No negative number
    }

    // Process the remaining windows
    for (int i = k; i < arr.size(); i++) {
        // Remove elements that are out of the current window
        if (!q.empty() && q.front() <= i - k) {
            q.pop();
        }

        // Add the current element if it is negative
        if (arr[i] < 0) {
            q.push(i);
        }

        // Add the result for the current window
        if (!q.empty()) {
            result.push_back(arr[q.front()]);
        } else {
            result.push_back(0); // No negative number
        }
    }

    return result;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends