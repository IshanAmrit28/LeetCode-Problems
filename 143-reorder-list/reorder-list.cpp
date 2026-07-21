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

        if(head == NULL || head->next == NULL)
            return;

        // Find middle
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *head2 = slow->next;
        slow->next = NULL;

        ListNode *prev = NULL;

        while(head2){
            ListNode *temp = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = temp;
        }

        head2 = prev;
        ListNode *head1 = head;

        // Merge
        while(head2){
            ListNode *h1 = head1->next;
            ListNode *h2 = head2->next;

            head1->next = head2;
            head2->next = h1;

            head1 = h1;
            head2 = h2;
        }
    }
};