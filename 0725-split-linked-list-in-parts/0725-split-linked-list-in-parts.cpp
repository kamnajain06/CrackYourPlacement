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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        vector<ListNode*> ans;
        int size = 0;
        vector<int> sizes;
        while(curr != NULL){
            size++;
            curr= curr->next;
        }
        for(int i=0; i<k; i++){
            sizes.push_back(size/k);
        }
        int t = size%k;
        for(int i=0; i<t; i++){
            sizes[i]++;
        }
        int a = 0;
        ListNode* prev = NULL;
        while(a < sizes.size()){
            vector<ListNode*> values;
            ans.push_back(head);
            for(int i=0; i<sizes[a]; i++){
                if(head == NULL) return ans;
                prev = head;
                head = head->next;
            }
            if(prev != NULL)prev->next = NULL;
            a++;
        }
        return ans;
    }
};