//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution {
public:
    bool is_palindrome(string&s,int start,int end){
        
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(is_palindrome(s,i,j)){
                    string t = s.substr(i,j-i+1);
                    if(t.size()>ans.size()){
                        ans = t;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends