//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int safePos(int n, int k) {
        queue<int>q;

        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(q.size()>1){

            for(int i=1;i<k;i++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends