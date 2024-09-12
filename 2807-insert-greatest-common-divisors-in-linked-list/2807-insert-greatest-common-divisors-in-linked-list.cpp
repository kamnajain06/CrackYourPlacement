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
    int findGcd(int a , int b){
        int result = min(a,b);
        
        while(result > 0){
            if(a%result == 0 && b%result == 0) return result;
            else result --;
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
            ListNode* temp = new ListNode(findGcd(prev->val,curr->val));
            prev->next = temp;
            temp->next = curr;
            
        }
    return head;
        
    }
};