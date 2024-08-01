//{ Driver Code Starts
//Initial Template for C++

// CPP program for implementation of efficient 
// approach to find length of last word 
#include <bits/stdc++.h> 
using namespace std; 

int findLength(string s);

// Driver code 
int main() 
{ 
	int t;
	cin>>t;
	t+=1;
	bool flag = false;
	while(t--){
	    string s;
	    getline(cin,s);
	    if(!flag){
	        flag = true;
	        continue;
	    }
	    cout<<findLength(s)<<endl;
	}
	return 0;
} 

// } Driver Code Ends




int findLength(string s){
    int i = 0;
    int n = s.length();
    int sum = 0;
    int num = 0;
    while(i<n){
        if(s[i]!=' '){
            num++;
        }
        else if(s[i]==' '){
            if(num>0){
                sum = num;
            }
            num = 0;
        }
        i++;
    }
    if(num>0){
        sum = num;
    }
    
    return sum;
    
}