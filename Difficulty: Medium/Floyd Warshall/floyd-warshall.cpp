//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& arr) {
        vector<vector<int>>v(arr.size(),vector<int>(arr.size(),1e9));
        // yaha tak floyd warshall me sab jagah gand faad values padi h
        for(int i=0;i<arr.size();i++){
            v[i][i] = 0;
        }
        
        // yaha tak hum logo ne diagonal elements pr 0 store kr liye
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != -1) { // Assuming -1 means no edge
                    v[i][j] = arr[i][j];
                }
            }
        }
        
        for(int i=0;i<arr.size();i++){
            for(int src=0;src<arr.size();src++){
                for(int dest = 0;dest<arr.size();dest++){
                    v[src][dest] = min(v[src][dest],v[src][i]+v[i][dest]);
                }
            }
        }
        
        arr = v;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends