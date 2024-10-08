/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mpp;
        while(headA != NULL){
            mpp[headA]++;
            headA = headA->next;
        }
        while(headB != NULL){
            if(mpp.find(headB) != mpp.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};