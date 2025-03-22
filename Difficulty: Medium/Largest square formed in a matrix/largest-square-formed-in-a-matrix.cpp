//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {   
public:     
    int solve(vector<vector<int>>& mat, int row, int col, int x, int y, int &maxi, vector<vector<int>> &dp) {        
        if (x >= row || y >= col) {  
            return 0;  
        }  

        if (dp[x][y] != -1) {  
            return dp[x][y];  
        }  

        int right = solve(mat, row, col, x, y + 1, maxi, dp);  
        int down = solve(mat, row, col, x + 1, y, maxi, dp);  
        int diagonal = solve(mat, row, col, x + 1, y + 1, maxi, dp);  

        if (mat[x][y] == 1) {  
            dp[x][y] = 1 + min({right, down, diagonal});  
            maxi = max(maxi, dp[x][y]);  
            return dp[x][y];  
        }  

        return dp[x][y] = 0;  
    }  

    int maxSquare(vector<vector<int>>& mat) {  
        int row = mat.size();  
        int col = mat[0].size();  
        vector<vector<int>> dp(row, vector<int>(col, -1));  
        int maxi = 0;  

        // Har (i,j) se call karna padega kyunki GFG ke test cases random hain  
        for (int i = 0; i < row; i++) {  
            for (int j = 0; j < col; j++) {  
                solve(mat, row, col, i, j, maxi, dp);  
            }  
        }  

        return maxi;  
    }  
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends