//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
public:
    // Helper function to calculate the length of the linked list
    int getLen(Node* head) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    Node* reverseKGroup(Node* head, int k) {
        // Base case: if the list is empty or has less than k nodes
        if (!head) return head;

        // Reverse the first k nodes
        Node* curr = head;
        Node* prev = nullptr; // Initialize to nullptr
        Node* next = nullptr; // More descriptive name
        int count = 0; // Use count for clarity

        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Connect the reversed k nodes to the next group
        if (next != nullptr) { // Key Change: Check if there's a next group
            head->next = reverseKGroup(next, k); // head->next points to the reversed next group
        }

        return prev; // Return the new head of the reversed k nodes
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends