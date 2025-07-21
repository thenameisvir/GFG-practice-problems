class Solution {
  public:
    bool check(vector<int>& curr, vector<int>& prev) {
        return (prev[0] > curr[0] && prev[1] > curr[1]); // base should be strictly greater
    }

    int tab(vector<vector<int>>& boxes) {
        int n = boxes.size();
        vector<int> curr(n + 1, 0), prev(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int inc = 0;
                if (j == -1 || check(boxes[i], boxes[j])) {
                    inc = boxes[i][2] + prev[i + 1];
                }
                int exc = prev[j + 1];
                curr[j + 1] = max(inc, exc);
            }
            prev = curr;
        }

        return curr[0];
    }

    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = height.size();
        vector<vector<int>> boxes;

        for (int i = 0; i < n; i++) {
            int h = height[i];
            int w = width[i];
            int l = length[i];

            // 3 possible orientations with (baseL, baseW, height)
            boxes.push_back({max(w, l), min(w, l), h});
            boxes.push_back({max(h, l), min(h, l), w});
            boxes.push_back({max(h, w), min(h, w), l});
        }

        // Sort by base area in descending order
        sort(boxes.begin(), boxes.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] * a[1]) > (b[0] * b[1]);
        });

        return tab(boxes);
    }
};
