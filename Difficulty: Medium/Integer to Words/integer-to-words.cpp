//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    vector<pair<int, string>> mp = {
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"},
        {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"},
        {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"},
        {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
        {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
        {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}
    };
    string convertToWords(int n) {
       if(n==0) return "Zero";
       for(auto str:mp){
           if(n>=str.first){
               string a = "";
               if(n>=100){
                   a = convertToWords(n/str.first) + " ";
               }
               string b = str.second;
               string c = "";
               if(n%str.first!=0){
                   c = " " + convertToWords(n%str.first);
               }
               return a + b + c;
           }
       }
       
       return "";
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << "\"" << ans << "\""
             << "\n";
    }
    return 0;
}

// } Driver Code Ends