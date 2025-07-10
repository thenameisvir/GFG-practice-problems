/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    class compare{
        public:
        bool operator()(Node* a,Node* b){
            return a->data>b->data;
        }
    };
    Node* mergeKLists(vector<Node*>& arr) {
        if(arr.size()==0) return NULL;
        priority_queue<Node*,vector<Node*>,compare>pq;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=NULL){
                pq.push(arr[i]);
            }
        }
        
        
        // yaha tak first lists k process ho chuke hai 
        Node* madhur = new Node(0);
        Node* vir = madhur;
        
        while(!pq.empty()){
            Node* top = pq.top();pq.pop();
            
            vir->next = top;
            vir = top;
            
            if(top->next){
                pq.push(top->next);
            }
            
            
        }
        
        return madhur->next;
        
        
        
        
    }
};