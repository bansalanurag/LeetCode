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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (ListNode *head : lists) {
            while (head) {
                pq.push(head->val);
                head = head->next;
            }
        }
        ListNode *ans = NULL;
        ListNode *traverse = NULL;
        while (!pq.empty()) {
            if (ans == NULL) {
                ans = new ListNode(pq.top());
                traverse = ans;
            } else {
                traverse->next = new ListNode(pq.top());
                traverse = traverse->next;
            }
            pq.pop();
        }
        
        return ans;
    }
};
