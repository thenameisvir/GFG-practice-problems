//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
  
class Solution{
public:
    
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int>second;
        
        int s = q.size();
        
        int k = s/2;
        
        while(k){
            int f = q.front();
            q.pop();
            second.push(f);
            k--;
        }
        
        vector<int>v;
        
        while(!q.empty() && !second.empty()){
            int two = second.front();
            second.pop();
            int one = q.front();
            q.pop();
            v.push_back(two);
            v.push_back(one);
        }
        
        
        return v;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends