//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<pair<int,int>> st;

    Solution() {}

    void push(int x) {
        if (st.empty()) {
            st.push_back({x, x});
        } else {
            int mini = min(x, st.back().second);
            st.push_back({x, mini});
        }
    }

    void pop() {
        if (!st.empty())
            st.pop_back();
    }

    int peek() {
        if (!st.empty())
            return st.back().first;
        return -1;
    }

    int getMin() {
        if (!st.empty())
            return st.back().second;
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends