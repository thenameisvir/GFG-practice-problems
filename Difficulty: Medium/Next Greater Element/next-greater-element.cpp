//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        vector<int>ans(arr.size());
        stack<int>st;
        st.push(-1);
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            
            // Pop elements from stack until we find a greater element
            while (st.top() != -1 && st.top() <= curr) {
                st.pop();
            }
            
            // Assign the top of the stack as the next greater element for current element
            ans[i] = st.top();
            // Push the current element onto the stack
            st.push(curr);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends