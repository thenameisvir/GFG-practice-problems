//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long merge(vector<long long> &arr,int s,int e){
        int m = s+(e-s)/2;
        
        int lenleft = m-s+1;
        int lenright = e-m;
        
        long long count = 0;
        
        int *left = new int[lenleft];
        int *right = new int[lenright];
        
        int k = s;
        
        for(int i=0;i<lenleft;i++){
            left[i] = arr[k];
            k++;
        }
        
        k = m+1;
        
        for(int i=0;i<lenright;i++){
            right[i] = arr[k];
            k++;
        }
        
        int mainindex = s;
        int leftindex = 0;
        int rightindex = 0;
        
        while(leftindex<lenleft && rightindex<lenright){
            if(left[leftindex] <= right[rightindex]){
                arr[mainindex] = left[leftindex];
                leftindex++;
            }
            else{
                arr[mainindex] = right[rightindex];
                count += (lenleft - leftindex);  // Counting inversions
                rightindex++;
            }
            mainindex++;
        }
        
        while (leftindex < lenleft) {  
            arr[mainindex] = left[leftindex];  
            mainindex++;  
            leftindex++;  
        }  

        while (rightindex < lenright) {  
            arr[mainindex] = right[rightindex];  
            mainindex++;  
            rightindex++;  
        }  

        delete[] left;  // Free allocated memory  
        delete[] right; // Free allocated memory  

        return count; 
    }

    long long mergesort(vector<long long> &arr, int s, int e){
        if(s >= e) return 0;
        
        int m = s + (e - s) / 2;
        
        long long count = 0;
        
        count += mergesort(arr, s, m);
        count += mergesort(arr, m + 1, e);
        count += merge(arr, s, e);
        
        return count;
    }

    long long int inversionCount(vector<long long> &arr) {
        long long ans = mergesort(arr, 0, arr.size() - 1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends