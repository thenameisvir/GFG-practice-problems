//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isSafe(int x, int y, vector<vector<bool>>& vis, vector<vector<char>>& arr) {
        if (x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && !vis[x][y] && arr[x][y] == '1') {
            return true;
        }
        return false;
    }

    void bfs(vector<vector<bool>>& vis, vector<vector<char>>& arr, int i, int j) {
        queue<pair<int, int>> q;
        vis[i][j] = true;
        q.push({i, j});

        int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
        int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

        while (!q.empty()) {
            auto toppair = q.front();
            q.pop();
            int tempx = toppair.first;
            int tempy = toppair.second;

            for (int k = 0; k < 8; k++) {
                int newx = tempx + dx[k];
                int newy = tempy + dy[k];

                if (isSafe(newx, newy, vis, arr)) {
                    q.push({newx, newy});
                    vis[newx][newy] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& arr) {
        if (arr.empty()) return 0;

        int count = 0;
        vector<vector<bool>> vis(arr.size(), vector<bool>(arr[0].size(), false));

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                if (!vis[i][j] && arr[i][j] == '1') {
                    bfs(vis, arr, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends