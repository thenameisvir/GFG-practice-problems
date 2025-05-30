/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int front = 0;
        int rear = 0;
        int balance = 0;
        
        while(true){
            // petrol check kar gadi me kitna hai 
            balance+=gas[rear]-cost[rear];
            // ab jitna petrol hai uske hisab se check karenge kaha jana h
            if(balance>=0){
                // isme bar rear aage badhana hota hai 
                rear = (rear+1)%n;
                
                // check karle kahi answer tak pohoch toh nahi gaye 
                if(rear==front){
                    return front;
                }
            }
            else{
                // yaha apna jo fuel hai vo negative aya hai 
                // toh check kar kahi mai negative me hokr chakkar toh nhi laga aya hu
                if(front>rear){
                    return -1;
                }
                
                // isme front update hoga
                front = (rear+1)%n;
                rear = front;
                balance = 0;
                
                if(front==0){
                    return -1;
                }
            }
        }
        
        return -1;
        
    }
};