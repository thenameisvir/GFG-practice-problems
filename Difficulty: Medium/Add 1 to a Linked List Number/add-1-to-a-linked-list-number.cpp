//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* &head){
        Node* curr = head;
        Node* prev = NULL;
        Node* temp = NULL;
        
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        head = prev;
        
        return head;
    }
    Node* addOne(Node* head) {
        
        
       head = reverse(head);
    
    // Add one 
    int carry = 1;
    Node* temp = head;
    while(temp->next!=NULL){
        int totalSum = temp->data+carry;
        int digit = totalSum%10;
        carry = totalSum/10;
        
        temp->data = digit;
        temp = temp->next;
        
        if(carry==0){
            break;
        }
    }
    
    // Process Last Node
    if(carry!=0){
        int totalSum = temp->data + carry;
        int digit = totalSum%10;
        carry = totalSum/10;
        
        temp->data = digit;
        
        
        if(carry!=0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }
    
    
    head = reverse(head);
        return head;
        
        
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends