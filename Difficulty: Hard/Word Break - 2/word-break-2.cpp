// User function Template for C++
class Solution {
  public:
    bool check(vector<string>& arr,string &str){
        for(auto i:arr){
            if(i==str){
                return true;
            }
        }
        
        return false;
    }
    void solve(vector<string>& arr,string& s,string& temp,int index,vector<string>&ans)
    {
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        
        string str = "";
        for(int i=index;i<s.size();i++){
            str+=s[i];
            
            if(check(arr,str)){
                string newTemp = "";
                if(temp.empty()){
                    newTemp = str;
                }
                else{
                    newTemp = temp + " " + str;
                }
                
                solve(arr,s,newTemp,i+1,ans);
            }
        }
        
    }
    vector<string> wordBreak(vector<string>& arr, string& s) {
        vector<string>ans;
        string temp = "";
        solve(arr,s,temp,0,ans);
        return ans;
    }
};
