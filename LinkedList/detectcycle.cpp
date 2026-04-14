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
    ListNode *detectCycle(ListNode *head) {
        //agr single node wala case hai to 
        if(head == nullptr || head->next == nullptr) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast)
            {
                break;
            }
        }

        //agr fast last ya second last mai hai to return null krdo 
        if(fast == nullptr || fast -> next  == nullptr) return NULL;
        slow = head;
        //yaha s dono ko 1-1 krke chalo and figure out dikt kha hai 
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == fast) return slow;
        return NULL;
    }
};
