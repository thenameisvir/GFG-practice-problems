class Solution {
  public:
    string FirstNonRepeating(string &str) {
        unordered_map<char, int> mp;
        string ans = "";
        queue<char> q;
        
        for (int i = 0; i < str.size(); i++) {
            mp[str[i]]++;
            q.push(str[i]);

            while (!q.empty() && mp[q.front()] > 1) {
                q.pop();
            }

            if (!q.empty()) {
                ans.push_back(q.front());
            } else {
                ans.push_back('#');
            }
        }
        
        return ans;
    }
};
