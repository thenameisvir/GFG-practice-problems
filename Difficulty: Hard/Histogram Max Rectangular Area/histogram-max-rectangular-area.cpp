//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    vector<long long> nextSmaller(vector<long long> &arr) {
        int n = arr.size();
        vector<long long> ans(n);
        stack<int> st;
        st.push(-1);
        
        for (int i = n - 1; i >= 0; i--) {
            long long curr = arr[i];
            
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            
            ans[i] = (st.top() == -1) ? n : st.top();
            st.push(i);
        }
        
        return ans;
    }
    
    vector<long long> prevSmaller(vector<long long> &arr) {
        int n = arr.size();
        vector<long long> ans(n);
        stack<int> st;
        st.push(-1);
        
        for (int i = 0; i < n; i++) {
            long long curr = arr[i];
            
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }
    
    long long getMaxArea(vector<long long> &hist) {
        int n = hist.size();
        vector<long long> next = nextSmaller(hist);
        vector<long long> prev = prevSmaller(hist);
        
        long long maxArea = 0;  // Initialize to 0 to ensure positive values

        for (int i = 0; i < n; i++) {
            long long length = hist[i];
            long long width = next[i] - prev[i] - 1;
            long long area = length * width;  // Calculate the area for the current bar
            
            maxArea = max(maxArea, area);  // Update maxArea if we find a larger area
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends