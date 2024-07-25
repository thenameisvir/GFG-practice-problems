//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
  public:
    bool ispossible(int arr[], int n, int k, long long m) {
        long long sum = 0;
        int p = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] > m) {
                return false;
            }
            if (arr[i] + sum > m) {
                p++;
                sum = arr[i];
                if (p > k) {
                    return false;
                }
            } else {
                sum += arr[i];
            }
        }
        return true;
    }

    long long minTime(int arr[], int n, int k) {
        long long s = *max_element(arr, arr + n);
        long long e = accumulate(arr, arr + n, 0LL);
        long long ans = -1;
        while (s <= e) {
            long long m = s + (e - s) / 2;
            if (ispossible(arr, n, k, m)) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends