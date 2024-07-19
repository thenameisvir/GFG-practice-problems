//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pivot(vector<int>& arr){
        int s = 0;
        int n = arr.size();
        int e = n-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(s==e) return s;
            else if(arr[m]>arr[m+1] && m+1<n){
                return m;
            }
            else if(arr[m-1]>arr[m] && m-1>=0){
                return m-1;
            }
            else if(arr[m]>arr[s]){
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        return -1;
    }
    int binary(vector<int>& arr,int s,int e,int target){
        while(s<=e){
            int m = s+(e-s)/2;
            if(arr[m]==target){
                return m;
            }
            else if(arr[m]>target){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int index = pivot(arr);
        int ans = -1;
        int n = arr.size();
        if(index==-1){
            ans = binary(arr,0,n-1,target);
        }
        else if(target>=arr[0]&&target<=arr[index]){
            ans = binary(arr,0,index,target);
        }
        else{
            ans = binary(arr,index+1,n-1,target);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends