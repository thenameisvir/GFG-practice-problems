//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string FirstNonRepeating(string &s) {
        queue<char>q;
        int f[26] = {0};
        string str = "";
        
        for(int i=0;i<s.length();i++){
            //Taking the character is our first step
            char ch = s[i];
            // Updating the frequency is the second step
            f[ch-'a']++;
            // pushing it into the queue is our third step
            q.push(ch);
            
            //our logic to take out the answer
            while(!q.empty()){
                int ch2 = q.front();
                if(f[ch2-'a']>1){
                    q.pop();
                }
                else{
                    str.push_back(ch2);
                    break;
                }
            }
            
            if(q.empty()){
                str.push_back('#');
            }
        }
        
        
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends