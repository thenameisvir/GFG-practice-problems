
class Solution {
  public:
    string decodedString(string &s) {
        stack<string> stStr;
        stack<int> stNum;
        
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                stNum.push(num);
            } else if (s[i] == '[') {
                stStr.push("[");  // marker for substring start
                i++;
            } else if (s[i] == ']') {
                string temp = "";
                // pop strings until we hit '['
                while (!stStr.empty() && stStr.top() != "[") {
                    temp = stStr.top() + temp;
                    stStr.pop();
                }
                if (!stStr.empty() && stStr.top() == "[") {
                    stStr.pop();
                }
                
                int count = 1;
                if (!stNum.empty()) {
                    count = stNum.top();
                    stNum.pop();
                }
                
                string repeated = "";
                for (int j = 0; j < count; j++) {
                    repeated += temp;
                }
                stStr.push(repeated);
                i++;
            } else {
                // accumulate consecutive letters
                string letters = "";
                while (i < n && isalpha(s[i])) {
                    letters += s[i];
                    i++;
                }
                stStr.push(letters);
            }
        }
        
        string result = "";
        while (!stStr.empty()) {
            result = stStr.top() + result;
            stStr.pop();
        }
        
        return result;
        
    }
};