class Solution {
public:
    ListNode* returnMid(ListNode* start){
        ListNode* slow = start;
        ListNode* fast = start->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* curr1 = left;
        ListNode* curr2 = right;
        ListNode* newHead = nullptr;
        

        if(left->val < right->val){
            newHead = left;
            left = left->next;
        }else{
            newHead = right;
            right = right->next;
        }
        ListNode* curr = newHead;
        while(left != NULL && right != NULL ){
            if(left->val < right->val){
                curr->next = left;
                left = left->next;
            }else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        while(left != NULL ){
            curr->next = left;
            left = left->next;
            curr = curr->next;
        }
        while(right != NULL ){
            curr->next = right;
            right = right->next;
            curr = curr->next;
        }
        return newHead;
    }

    ListNode* sortList(ListNode* head) {
       if(head == NULL || head->next == NULL) return head;
        ListNode* mid = returnMid(head);
        ListNode* nextMid = mid->next;
        mid->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(nextMid);
        ListNode* ans = merge(left,right);
        return ans;
    }
};