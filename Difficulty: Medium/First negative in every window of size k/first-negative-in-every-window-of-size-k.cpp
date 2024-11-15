//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        queue<int>q;
        
        vector<int>v;
        
        // pehla kaam hai k pehle window ko process krdo
        
        for(int i=0;i<k;i++){
            int num = arr[i];
            
            if(num<0){
                q.push(i);
            }
        }
        
        // now process the answer of first window into the vector
        
        if(!q.empty()){
            v.push_back(arr[q.front()]);
        }
        else{
            v.push_back(0);
        }
        
        
        // now process the other windows 
        
        for(int i=k;i<arr.size();i++){
            // check karo kahi out of bound to nahi hai
            if(!q.empty() && q.front()<=i-k){
                q.pop();
            }
            
            // now process the current element 
            // bhai iski bhi to izzat krle kya pta negative ho 
            
            if(arr[i]<0){
                q.push(i);
            }
            
            
            if(!q.empty()){
            v.push_back(arr[q.front()]);
        }
        else{
            v.push_back(0);
        }
        }
        
        
        return v;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends