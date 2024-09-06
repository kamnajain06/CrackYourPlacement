/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* &head, ListNode* &curr, ListNode* &prev){
        if(curr == head){
            prev = curr;
            head = curr->next;
        }else if(curr->next == NULL){
            prev->next = NULL;
        }else{
            prev->next = curr->next;
        }
        curr = curr->next;
        return;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            if(mpp.find(curr->val) != mpp.end()){
                deleteNode(head,curr,prev);
            }else{
                prev = curr;    
                curr = curr->next;  
            }
        }
        
        return head;
    }
};