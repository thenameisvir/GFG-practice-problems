//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(vector<int>& arr) {
    vector<int> ans(arr.size());
    stack<pair<int, int>> st;

    for (int i = 0; i < arr.size(); i++) {
        // Pop elements from the stack while the current element is greater
        while (!st.empty() && arr[i] >= st.top().first) {
            st.pop();
        }

        // If the stack is empty, span is the entire range so far
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top().second;
        }

        // Push the current element and its index onto the stack
        st.push({arr[i], i});
    }

    // Adjust the spans
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = i - ans[i];
    }

    return ans;
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends