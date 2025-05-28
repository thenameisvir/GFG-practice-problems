class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> v;

        // Process first window
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0)
                q.push(i);
        }

        if (!q.empty())
            v.push_back(arr[q.front()]);
        else
            v.push_back(0);

        // Process rest of the windows
        for (int i = k; i < arr.size(); i++) {
            // Remove out-of-window indices
            while (!q.empty() && q.front() <= i - k)
                q.pop();

            if (arr[i] < 0)
                q.push(i);

            if (!q.empty())
                v.push_back(arr[q.front()]);
            else
                v.push_back(0);
        }

        return v;
    }
};
