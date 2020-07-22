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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy_head(-1);
        dummy_head.next = head;
        ListNode *left = &dummy_head;
        ListNode *right = &dummy_head;
        
        for (int i = 0; i < n; i++) {
            right = right->next;
        }

        while (right->next) {
            right = right->next;
            left = left->next;
        }
        
        left->next = left->next->next;

        return dummy_head.next;
        
    }
};