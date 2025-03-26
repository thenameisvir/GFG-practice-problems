//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

    class Solution {
  public:
    void solve(string &s, int index, vector<string>& ans, unordered_set<string>& seen) {
        if (index == s.size()) {
            if (seen.find(s) == seen.end()) {
                ans.push_back(s);
                seen.insert(s);
            }
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (i != index && s[i] == s[index]) continue;  // Skip duplicate swaps
            swap(s[i], s[index]);
            solve(s, index + 1, ans, seen);
            swap(s[i], s[index]);  // Backtrack
        }
    }

    vector<string> findPermutation(string &s) {
        sort(s.begin(), s.end());  // Sorting helps in detecting duplicates
        vector<string> ans;
        unordered_set<string> seen;
        solve(s, 0, ans, seen);
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends