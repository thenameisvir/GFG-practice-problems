//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int ans(int n){
        if(n==1) return 0; // ye base case aunga revise karne abhi
        if(n==2) return 1;
        
        int a = (n-1) * (ans(n-2) + ans(n-1));
        
        return a;
        
    }
    int countDer(int n) {
        return ans(n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.countDer(N) << "\n";
    }
    return 0;
}
// } Driver Code Ends