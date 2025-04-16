//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int total = a.size() + b.size();
        for (int i = 0; i < b.size(); i++) {
            a.push_back(b[i]);  // Step 1: Merge into a
        }

        sort(a.begin(), a.end()); // Step 2: Sort

        int a1 = a.size() - b.size();  // Original size of a
        int b1 = b.size();             // Original size of b

        for (int i = 0; i < b1; i++) b.pop_back();  // Step 3: Clear b

        // Step 4: Fill correct values back into a and b
        vector<int> merged = a; // just to keep a copy for safe restoration

        a.clear();
        for (int i = 0; i < a1; i++) {
            a.push_back(merged[i]);
        }

        for (int i = a1; i < total; i++) {
            b.push_back(merged[i]);
        }
    }
};





//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends