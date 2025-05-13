//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
        if(r > n) return 0;
        if(r > n - r) r = n - r; // Symmetry property

        long long res = 1;
        for(int i = 0; i < r; ++i){
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends