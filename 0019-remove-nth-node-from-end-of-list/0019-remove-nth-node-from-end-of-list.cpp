class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(head->next == NULL && n == 1) return NULL;
        ListNode* next = head->next;

        while(next != NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        curr->next = prev;

        prev = NULL;
        head = curr;
        next = curr->next;
        
        n--;
        while(n-- > 0){
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

        prev = NULL;
        curr = head;
        next = head->next;

        while(next != NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        curr->next = prev;
        head = curr;
        
        return head;
    }
};