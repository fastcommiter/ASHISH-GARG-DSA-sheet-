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
    ListNode* middleNode(ListNode* head) {
        /* APPROACH -- just start with two pointers and move one with normal pase and
            another with twice the speed of the first one , once the last reaches the end u will be at the middle 
            this is called fast and slow pointer
        */

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
