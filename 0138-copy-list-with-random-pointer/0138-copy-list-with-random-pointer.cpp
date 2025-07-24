/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<int,Node*> mpp2;
        unordered_map<Node*, int> mpp1;
        Node* curr = head->next;
        Node* newHead = new Node(head->val);
        mpp1[head] = 0;
        mpp2[0] = newHead;
        Node* prev = newHead;
        int i = 1;
        while(curr){
            Node* temp = new Node(curr->val);
            prev->next = temp;
            prev = temp;
            mpp1[curr] = i;
            mpp2[i++] = temp;
            curr = curr->next;
        }
        curr = head;
        Node* newCurr = newHead;
        while(curr){
            if(curr->random != NULL){
                newCurr->random = mpp2[mpp1[curr->random]];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};