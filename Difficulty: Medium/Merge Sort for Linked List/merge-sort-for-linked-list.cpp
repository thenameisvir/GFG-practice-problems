//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
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
    Node* findMid(Node* &head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    Node* merge(Node* &left,Node* &right){
        Node* ans = new Node(-1);
        Node* mptr = ans;
        
        while(left&&right){
            if(left->data<=right->data){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }
        
        if(left){
            mptr->next = left;
        }
        if(right){
            mptr->next = right;
        }
        
        
        return ans->next;
    }
    Node* mergeSort(Node* head) {
        // base case condition
        if(head==NULL || head->next==NULL) return head;
        // initialisation of linked list
        Node* left = head;
        Node* mid = findMid(head);
        Node* right = mid->next;
        mid->next = NULL;
        
        //sort the linked list
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        // merge both of the linked list
        
        Node* finalAns = merge(left,right);
        
        return finalAns;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends