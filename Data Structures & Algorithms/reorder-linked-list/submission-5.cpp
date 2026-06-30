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
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> order;
        ListNode dummy;
        ListNode* result = &dummy;
        int i = 0;
        while(head != nullptr){
            order[i] = head;
            head = head->next;
            i++;
        }
        int l = 0;
        int r = order.size()-1;
        for(int j = 0; j < order.size(); j++){
            if(j % 2 == 0){
                result->next = order[l];
                l++;
            }else{
                result->next = order[r];
                r--;
            }
            result = result->next;
        }
        result->next = nullptr;
    }
};
