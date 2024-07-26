//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool ispossible(vector<int> &stalls,int k,int sol){
        int c = 1;
        int pos = stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i] - pos>=sol){
                c++;
                pos = stalls[i]; // one more cow has been placed
            }
            if(c==k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int s = 0;
        int e = stalls[stalls.size()-1]-stalls[0];
        int ans = -1;
        
        while(s<=e){
            int m = s+(e-s)/2;
            if(ispossible(stalls,k,m)){
                ans = m;
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends