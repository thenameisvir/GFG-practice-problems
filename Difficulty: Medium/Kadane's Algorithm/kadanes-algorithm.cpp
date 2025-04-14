//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        
        int maxi = arr[0];
        int sum = 0;
        
        for(int i=0;i<arr.size();i++){
            // kadanes me sum karo sabse pehle
            sum +=arr[i];
            // fir max ko update karo
            
            maxi = max(maxi,sum);
            
            // agar sum negative hai toh update kardo
            
            if(sum<0) sum = 0;
        }
        
        return maxi;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl << "~" << endl;
    }
}
// } Driver Code Ends