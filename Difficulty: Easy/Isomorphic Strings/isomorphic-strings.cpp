//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        char start = 'a';
        char arr[300] = {0};
        char start2 = 'a';
        char arr2[300] = {0};
        string str = "";
        string strr = "";
        
        for(auto ch:str1){
            if(arr[ch]==0){
                arr[ch] = start;
                start++;
            }
        }
        for(auto ch:str2){
            if(arr2[ch]==0){
                arr2[ch] = start2;
                start2++;
            }
        }
        
        for(auto ch:str1){
            char p = arr[ch];
            str.push_back(p);
        }
        
        for(auto ch:str2){
            char p = arr2[ch];
            strr.push_back(p);
        }
        
        if(str==strr){
            return true;
        }
        return false;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends