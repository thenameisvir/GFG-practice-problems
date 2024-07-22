//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    bool isPossibleSolution(int arr[],int n,int M,int m){
        int sum = 0;
        int c = 1;
        for(int i=0;i<n;i++){
            if(arr[i]>m){
                return false;
            }
            if(sum+arr[i]>m){
                c++;
                sum = arr[i];
                if(c>M){
                    return false;
                }
            }
            else{
                sum+=arr[i];
            }
        }
        return true;
    }
    long long findPages(int n, int arr[], int M) {
        if(M>n) return -1;
        int s = 0;
        int e = accumulate(arr,arr+n,0);
        int ans = -1;
        
        while(s<=e){
            int m = s+(e-s)/2;
            if(isPossibleSolution(arr,n,M,m)){
                ans = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends