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
    
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }
        return len;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = getLength(l1);
        int b = getLength(l2);
        ListNode *l3 = NULL;
        
        if (a == 0 && b != 0) 
            return l2;
        else if (a != 0 && b == 0)
            return l1;
        else if (a == 0 && b == 0)
            return l3;        
            
            
        if (a < b) {
            ListNode *temp = l1;
            l1 = l2;
            l2 = temp;
        }
        
        ListNode *temp = l3;
        int sum = 0, carry = 0;
        while (l2) {
            sum = carry + l1->val + l2->val;
            if (sum > 9) {
                carry = sum / 10;
                sum  = sum % 10;
            } else {
                carry = 0;
            }
            
            if (l3 == NULL) {
                l3 = new ListNode(sum);
                temp = l3;
            } else {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            sum = carry + l1->val;
            if (sum > 9) {
                carry = sum / 10;
                sum  = sum % 10;
            } else {
                carry = 0;
            }
            
            if (l3 == NULL) {
                l3 = new ListNode(sum);
                temp = l3;
            } else {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            
            l1 = l1->next;            
        }
        
        if (carry) {
            temp->next = new ListNode(carry);        
        }
        
        return l3;
    }
};
