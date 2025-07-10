class Solution {
  public:
    class Info{
        public:
        int data;
        int rowIndex;
        int colIndex;
        
        Info(int data,int rowIndex,int colIndex){
            this->data = data;
            this->rowIndex = rowIndex;
            this->colIndex = colIndex;
        }
    };
    
    class compare{
        public:
        bool operator()(Info* a,Info* b){
            return a->data > b->data;
        }
    };
    
    void solve(vector<vector<int>> arr,int n,int k,vector<int>&ans){
        // step 1 
        priority_queue<Info*,vector<Info*>,compare>pq; // initialise min heap
        
        // process first window
        for(int i=0;i<n;i++){
            Info* temp = new Info(arr[i][0],i,0);
            pq.push(temp);
        }
        
        // ab thoda sliding window wala logic chalyenge
        while(!pq.empty()){
            Info* temp = pq.top(); pq.pop();
            int topdata = temp->data;
            int toprow = temp->rowIndex;
            int topcol = temp->colIndex;
            
            ans.push_back(topdata);
            
            // ab yaha ata hai main logic apna 
            
            if(topcol+1<n){
                Info* newNode = new Info(arr[toprow][topcol+1],toprow,topcol+1);
                pq.push(newNode);
            }
        }
    }
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        
        int n = arr.size();
        int k = arr[0].size();
        
        vector<int>ans;
        
        solve(arr,n,k,ans);
        return ans;
    }
};