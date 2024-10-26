//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack) {
        // code here..
        int k=sizeOfStack/2 ;
        stack<int> st1;
        int count=0;
        while(count<k){
            int x=s.top();
            s.pop();
            st1.push(x);
            count++ ;
        }
        s.pop();
        while(!st1.empty()){
            s.push(st1.top());
            st1.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends