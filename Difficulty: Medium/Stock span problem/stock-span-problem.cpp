class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int>ans;
        stack<pair<int,int>>st;
        ans.push_back(1);
        st.push({arr[0],1});
        
        for(int i=1;i<arr.size();i++){
            int span = 1;
            while(!st.empty() && arr[i]>=st.top().first){
                span += st.top().second;
                st.pop();
            }
            
            st.push({arr[i],span});
            ans.push_back(span);
            
        }
        
        return ans;
        
        
    }
};