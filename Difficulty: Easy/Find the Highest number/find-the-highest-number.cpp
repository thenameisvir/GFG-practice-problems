//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        int s = 0;
        int e = arr.size()-1;
        int m = s+(e-s)/2;
        while(s<e){
            if(arr[m]<arr[m+1]){
                s = m+1;
            }
            else{
                e = m;
            }
            m = s+(e-s)/2;
        }
        return arr[e];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends