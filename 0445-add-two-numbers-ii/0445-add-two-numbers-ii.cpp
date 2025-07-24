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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        ListNode* curr = l1;
        while(curr){
            st1.push(curr->val);
            curr = curr->next;
        }
        curr = l2;
        while(curr){
            st2.push(curr->val);
            curr = curr->next;
        }
        int inc = 0;
        ListNode* head = NULL, *prev = NULL;
        while(!st1.empty() && !st2.empty()){
            int val1 = st1.top();
            int val2 = st2.top();
            st1.pop(); st2.pop();
            int sum = val1 + val2 + inc;
            inc = 0;
            if(sum > 9){
                inc = 1;
                sum -= 10;
            }
            ListNode* temp = new ListNode(sum);
            if(!head)head = temp;
            if(!prev) prev = temp;
            else{
                prev->next = temp;
                prev = temp;
            }
        }
        while(!st1.empty()){
            int val1 = st1.top();
            st1.pop();
            int sum = val1 + inc;
            inc = 0;
            if(sum > 9){
                inc = 1;
                sum -= 10;
            }
            ListNode* temp = new ListNode(sum);
            if(!head)head = temp;
            if(!prev) prev = temp;
            else{
                prev->next = temp;
                prev = temp;
            }
        }
        while(!st2.empty()){
            int val2 = st2.top();
            st2.pop();
            int sum = val2 + inc;
            inc = 0;
            if(sum > 9){
                inc = 1;
                sum -= 10;
            }
            ListNode* temp = new ListNode(sum);
            if(!head)head = temp;
            if(!prev) prev = temp;
            else{
                prev->next = temp;
                prev = temp;
            }
        }

        curr = head;
        prev = NULL;
        ListNode* nextptr = NULL;

        while(curr){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }

        if(inc){
            ListNode* node = new ListNode(1);
            node->next = prev;
            prev = node;
        }
        return prev;
    }
};