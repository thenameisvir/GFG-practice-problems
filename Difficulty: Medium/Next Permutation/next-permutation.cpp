//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
       int pivot = -1;
       int n = arr.size()-1;
       for(int i = n-1;i>=0;i--){
           if(arr[i]<arr[i+1]){
               pivot = i;
               break;
           }
       }
       
       // yaha tak maine pivot dhund lia hai ache se
       if(pivot==-1){
           reverse(arr.begin(),arr.end());
           return;
       }
       // yaha tak kuch return hona hota toh ab tak ho jata
       
       for(int i=n;i>pivot;i--){
           if(arr[pivot]<arr[i]){
               swap(arr[i],arr[pivot]);
               break;
           }
       }
       
       // dhyan rakhna humesha upar statement me break bhhot nec hai
       
       reverse(arr.begin() + pivot+1,arr.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends