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
    
    ListNode* reverseList(ListNode* head) {
        if (!head->next) return head;
        
        ListNode *p = head;        
        ListNode *q = head->next;
        ListNode *r = NULL;
        
        while (q) {
            p->next = r;
            r = p;
            p = q;
            q = q->next;
        }
        p->next = r;
        return p;
    }
    
    int getDecimalValue(ListNode* head) {
        if (!head) return 0;
        
        int ans = 0, i = 0;
        
        ListNode *temp = reverseList(head);                
        while (temp) {
            if (temp->val != 0)
                ans += temp->val * (1 << i);            
            temp = temp->next;
            i += 1;
        }
        
        return ans;
    }
};
