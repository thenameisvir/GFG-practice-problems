//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool ispossible(vector<int> &arr,int k,int sol){
        int c = 1;
        int pos = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-pos>=sol){
                c++;
                pos = arr[i];
            }
            
            if(c==k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int s = 0;
        int ans = -1;
        int e = arr[arr.size()-1] - arr[0];
        while(s<=e){
            int m = s+(e-s)/2;
            if(ispossible(arr,k,m)){
                s = m+1;
                ans = m;
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