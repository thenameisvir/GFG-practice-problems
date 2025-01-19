//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    int data = arr[0];
    Node* head = new Node(data);
    Node* tail = head;
    for (int i = 1; i < arr.size(); ++i) {
        data = arr[i];
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
// structure of the node is as follows

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
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
       // is code ko karne k liye apan karenge ye
       map<int,Node*>mp;
       // map bana lia hai ab thoda logic logic khelte hai
       
       Node* curr = head1; // isko iterate karte rhenge poore raste
       
       while(curr){
           // yaha apan map me store kr lenge
           mp[curr->data] = curr;
           curr = curr->next;
       }
       
       curr = head2;
       
       while(curr){
           // yaha apan map me store kr lenge
           mp[curr->data] = curr;
           curr = curr->next;
       }
       
       // ab yaha apna fayda ye hua k values overwrite hogyi ekdum 
       
       curr = 0;
       // or ek new ll banao jo ki return karoge
       Node* UL = 0;
       
       for(auto it = mp.begin();it!=mp.end();it++){
           // yaha mujhe empty wala case dekhna padega
           if(!UL){
               UL = it->second;
               curr = UL;
               // simple
               // yaha maine kiya kya ki bc ul p pehli node daal di
               // aur ab baki ka code dekhunga
           }
           else{
               curr->next = it->second;
               curr = curr->next;
           }
       }
       curr->next = 0;
       return UL;
       
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        Node* first = buildList();

        Node* second = buildList();
        Solution obj;
        Node* head = obj.makeUnion(first, second);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends