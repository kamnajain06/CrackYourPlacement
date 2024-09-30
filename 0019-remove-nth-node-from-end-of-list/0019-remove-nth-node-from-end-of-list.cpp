class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(head->next == NULL && n == 1) return NULL;
        ListNode* next = head->next;

        int cnt = 0;

        while(curr != NULL){
            cnt++;
            curr = curr->next;
        }
        curr = head;
        
        int nFromFront = cnt - n + 1;
        nFromFront--;
        while(nFromFront-- > 0){
            prev = curr;
            curr = next;
            next = curr->next;
        }
        if(curr == head){
            head = curr->next;
        }else if(curr->next == NULL){
            prev->next = NULL;
        }else{
            prev->next = next;
        }
        
        return head;
    }
};