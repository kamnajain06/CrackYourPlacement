class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;

        ListNode* curr = head;
        ListNode* next = curr->next;
        ListNode* temp = curr->next;
        int cnt = 0;

        while(curr->next != NULL){
            cnt++;

            if(next->next == NULL && cnt%2 != 0){
                break;
            }

            curr->next = curr->next->next;
            curr = next;
            next = curr->next;
        }

        curr->next = temp;

        return head;
    }
};