class Solution {
  public:
    int celebrity(vector<vector<int> >& arr) {
        // code here
        int cel = -1;
        for(int i=0;i<arr.size();i++){
            bool check = true;
            for(int j=0;j<arr.size();j++){
                if(arr[i][j]==1 && i!=j){
                    check = false;
                    break;
                }
            }
            
            if(check){
                for(int k = 0;k<arr.size();k++){
                if(arr[k][i]==0){
                    check = false;
                    break;
                }
            }
            }
            
            if(check){
                cel = i;
            }
            
        }
        
        return cel;
    }
};