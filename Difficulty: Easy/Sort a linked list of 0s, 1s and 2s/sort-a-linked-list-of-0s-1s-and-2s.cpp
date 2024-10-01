//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* returnMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* left, Node* right){
        Node* newHead = nullptr;
        if(left -> data < right->data){
            newHead = left;
            left = left->next;
        }else{
            newHead = right;
            right = right->next;
        }
        Node* curr = newHead;
        
        while(left != NULL && right != NULL){
            if(left -> data < right->data){
                curr->next = left;
                left = left->next;
            }else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        while(left != NULL){
            curr->next = left;
            left = left->next;
            curr = curr->next;
        }
        while(right != NULL){
            curr->next = right;
            right = right->next;
            curr = curr->next;
        }
        return newHead;
    }
    Node* segregate(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        Node* mid = returnMid(head);
        Node* nextMid = mid->next;
        mid->next = NULL;
        Node* left = segregate(head);
        Node* right = segregate(nextMid);
        
        return merge(left,right);
        
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends