//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> q; // Deque to store indices for maximum elements
        vector<int> v; // Result vector

        // Process the first window
        for (int i = 0; i < k; i++) {
            // Remove all smaller elements from the back of the deque
            while (!q.empty() && arr[q.back()] <= arr[i]) {
                q.pop_back();
            }
            q.push_back(i); // Add current index
        }

        // Add the maximum of the first window
        v.push_back(arr[q.front()]);

        // Process the remaining windows
        for (int i = k; i < arr.size(); i++) {
            // Remove indices that are out of the current window
            if (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            // Remove all smaller elements from the back of the deque
            while (!q.empty() && arr[q.back()] <= arr[i]) {
                q.pop_back();
            }

            // Add the current index
            q.push_back(i);

            // Add the maximum of the current window
            v.push_back(arr[q.front()]);
        }

        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends