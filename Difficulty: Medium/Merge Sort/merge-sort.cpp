//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends

class Solution
{
    public:
    void merge(int arr[], int s, int e)
    {
         int m = s+(e-s)/2;
         
         int lenleft = m-s+1;
         int lenright = e-m;
         
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
         
         // Fixing the comparison logic here
         while(leftindex < lenleft && rightindex < lenright){
             if(left[leftindex] <= right[rightindex]){  // Use left and right arrays
                 arr[mainindex] = left[leftindex];
                 leftindex++;
             }
             else{
                 arr[mainindex] = right[rightindex];
                 rightindex++;
             }
             mainindex++;
         }
         
         // Copy remaining elements of left[] if any
         while(leftindex < lenleft){
             arr[mainindex] = left[leftindex];
             leftindex++;
             mainindex++;
          }
          
         // Copy remaining elements of right[] if any
          while(rightindex < lenright){
              arr[mainindex] = right[rightindex];
              rightindex++;
              mainindex++;
          }
          
          // Free dynamically allocated memory
          delete[] left;
          delete[] right;
    }

    public:
    void mergeSort(int arr[], int s, int e)
    {
        if(s >= e) return;  // Base case: return if array has one or no element

        int m = s+(e-s)/2;
        
        mergeSort(arr, s, m);      // Sort first half
        mergeSort(arr, m+1, e);    // Sort second half
        
        merge(arr, s, e);          // Merge sorted halves
    }
};



//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends