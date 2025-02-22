//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int cols, vector<vector<int>> &heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        // {effort, {x, y}} -> Start from (0,0)
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // Directions: Up, Right, Down, Left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            pair<int, pair<int, int>> topElement = pq.top();
            pq.pop();
            int effort = topElement.first;
            int x = topElement.second.first;
            int y = topElement.second.second;

            // If we reached the destination, return the effort
            if (x == row - 1 && y == col - 1) return effort;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < row && ny < col) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));

                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return -1; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends