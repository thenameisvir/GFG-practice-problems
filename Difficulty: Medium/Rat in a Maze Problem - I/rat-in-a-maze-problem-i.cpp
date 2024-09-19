//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    void traverse(vector<vector<int>>& mat, vector<string>& res,
                  vector<vector<bool>>& visited, int row, int col,
                  string path) {
        int n = mat.size();
        if (row == n - 1 && col == n - 1 && mat[row][col] == 1) {
            res.push_back(path);
            return;
        }
        if (row == n || col == n || row < 0 || col < 0 || mat[row][col] == 0 ||
            visited[row][col])
            return;
        visited[row][col] = true;
        traverse(mat, res, visited, row, col + 1, path + 'R');
        traverse(mat, res, visited, row, col - 1, path + 'L');
        traverse(mat, res, visited, row + 1, col, path + 'D');
        traverse(mat, res, visited, row - 1, col, path + 'U');
        visited[row][col] = false;
    }
    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> res;
        vector<vector<bool>> visited(mat.size(),
                                     vector<bool>(mat.size(), false));
        traverse(mat, res, visited, 0, 0, "");
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends