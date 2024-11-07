//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M) {
        int n = M.size();
        
        
        
        stack<int>st;
        
        // initialised into the stack 
        for(int i=0;i<n;i++){
            st.push(i);
        }
        // discarded using the stack which is the best use of it and it 
        // will be gained within of that
        while(st.size()!=1){
            int a = st.top(); st.pop();
            
            int b = st.top(); st.pop();
            
            if(M[a][b]){
                st.push(b);
            }
            else{
                st.push(a);
            }
            
        }
        
        // now check whether you have taken correct person celebrity 
        int mightbeCel = st.top(); st.pop();
        
        
        for(int i=0;i<n;i++){
            if(M[mightbeCel][i]!=0){
                return -1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(M[i][mightbeCel]!=1 && i!=mightbeCel){
                return -1;
            }
        }
        
        
        return mightbeCel;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends