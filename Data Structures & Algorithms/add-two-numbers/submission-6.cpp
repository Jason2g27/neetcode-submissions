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
        int n = 1;
        int sum = 0;
        int carry = 0;
        ListNode start;
        ListNode* cur = &start;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;
            int val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            cur = cur->next;
        }
        return start.next;
    }
};
