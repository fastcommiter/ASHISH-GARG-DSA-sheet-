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
        int tt=0;

        if(head == nullptr) return nullptr;
        
        ListNode* temp = head;
        
        while(temp)
        {
            tt++;
            temp=temp->next;
        }

        int pos = tt - n + 1;
        temp=head;

        if(pos == 1)
        {
            temp=temp->next;
            head = temp;
            return head;
        }
        
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }

        if(temp->next == nullptr) return nullptr;
        
        temp->next = temp->next->next;
        
        return head;
    }
};
