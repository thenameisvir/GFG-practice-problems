//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    vector<int>nextSmaller(vector<int>&arr){
        vector<int>ans(arr.size());

        stack<int>st;

        st.push(-1);

        for(int i=arr.size()-1;i>=0;i--){
            int curr = arr[i];

            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }


        return ans;

    }
    vector<int>prevSmaller(vector<int>&arr){
        vector<int>ans(arr.size());

        stack<int>st;

        st.push(-1);

        for(int i=0;i<arr.size();i++){
            int curr = arr[i];

            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextSmaller(heights);

        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i] = next.size();
            }
        }

        vector<int>prev = prevSmaller(heights);


        int maxArea = INT_MIN;

        for(int i=0;i<heights.size();i++){
            int length = heights[i];

            int width = next[i]-prev[i]-1;


            int area = length*width;

            maxArea = max(maxArea,area);
        }


        return maxArea;
    }
  public:
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> heights(m, 0);  // Initialize heights for each column
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Update the histogram height for each column
            heights[j] = (M[i][j] == 0) ? 0 : heights[j] + 1;
        }
        // Calculate the maximum area for the current histogram
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends