class Solution {
  public:
    class Info{
        public:
        int data;
        int rowIndex;
        int colIndex;
        
        Info(int data,int row,int col){
            this->data = data;
            this->rowIndex = row;
            this->colIndex = col;
        }
    };
    class compare{
        public:
        bool operator()(Info* a,Info* b){
            return a->data > b->data;
        }
    };
    void solve(vector<vector<int>>& arr,vector<int>&ans){
        priority_queue<Info*,vector<Info*>,compare>pq;
        
        int maxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            Info* newNode = new Info(arr[i][0],i,0);
            pq.push(newNode);
            maxi = max(maxi,arr[i][0]);
        }
        
        int minRange = INT_MAX;
        while(!pq.empty()){
            Info* temp = pq.top();pq.pop();
            
            int mini = temp->data;
            if(maxi-mini<minRange){
                ans[0] = mini;
                ans[1] = maxi;
                minRange = maxi - mini;
            }
            
            int topCol = temp->colIndex;
            int topRow = temp->rowIndex;
            
            if(topCol + 1 < arr[topRow].size()){
                Info* newNode = new Info(arr[topRow][topCol+1],topRow,topCol+1);
                pq.push(newNode);
                
                if(maxi<newNode->data){
                    maxi = newNode->data;
                }
            }
            else{
                break; // means koi toh ek list hai jo khatam ho chuki hai 
            }
            
            
        }
        
        
        
    }
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        vector<int>ans(2);
        solve(arr,ans);
        return ans;
    }
};