//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>arr, int k){
	    sort(arr.begin(),arr.end());
	    int i = 0;
	    int j = 1;
	    set<pair<int,int>>ans;
	    while(j<arr.size()){
	        if(arr[j]-arr[i]==k){
	            ans.insert({arr[i],arr[j]});
	            i++;
	            j++;
	        }
	        else if(arr[j]-arr[i]>k){
	            i++;
	        }
	        else{
	            j++;
	        }
	        if(i==j){
	            j++;
	        }
	    }
	    return ans.size();
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends