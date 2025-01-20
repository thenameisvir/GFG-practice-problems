//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(vector<string>& v, int oCount, int cCount, string output) {
        if (oCount == 0 && cCount == 0) {
            v.push_back(output);
            return;
        }
        if (oCount > 0) {
            solve(v, oCount - 1, cCount, output + '(');
        }
        if (cCount > oCount) {
            solve(v, oCount, cCount - 1, output + ')');
        }
    }
    vector<string> AllParenthesis(int n) 
    {
       vector<string> v;
        solve(v, n, n, "");
        return v; 
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends