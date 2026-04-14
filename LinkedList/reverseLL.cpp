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
        //use the three pointer apporach in order to reverse the ll
        //use prev curr and next pointer 
        ListNode* prev = NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        //ab bs ghumate raho inko 
        while(curr)
        {
            next = curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
