/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while (fast && fast->next) {
            if ((slow = slow->next) == (fast = fast->next->next)) return true;
        }
        return false;
    }
};