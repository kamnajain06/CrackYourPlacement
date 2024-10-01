class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            ListNode* next = new ListNode(sum%10);
            temp->next = next;
            temp = temp->next;
            if(l1->next == NULL && l2->next == NULL && carry > 0){
                ListNode* newNode = new  ListNode(carry);
                temp->next = newNode;
                return head->next;
            }
            l1 = l1->next;
            l2 = l2->next;    
        }
        while(l1 == NULL && l2 != NULL){
            int sum = l2->val + carry;
            carry = sum/10;
            ListNode* next = new ListNode(sum%10);
            temp->next = next;
            temp = temp->next;
            if(l2->next == NULL && carry > 0){
                ListNode* newNode = new  ListNode(carry);
                temp->next = newNode;
                return head->next;
            }
            l2 = l2->next;
        }
        while(l2 == NULL && l1 != NULL){
            int sum = l1->val + carry;
            carry = sum/10;
            ListNode* next = new ListNode(sum%10);
            temp->next = next;
            temp = temp->next;
            if(l1->next == NULL && carry > 0){
                ListNode* newNode = new  ListNode(carry);
                temp->next = newNode;
                return head->next;
            }
            l1 = l1->next;
        }
        return head->next;
    }
};