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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = head;
        

        //counting the number of total nodes
        ListNode* temp = head;
        int cnt = 1;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        //this will store the number of total nodes 
        //second node at 
        int last = cnt - k;
        //mtlb yha tk to jana hai 
        for(int i =1;i<k;i++)
        {
            curr = curr->next;
        }
        for(int i =1;i<last;i++)
        {
            prev = prev->next;
        }
        swap(prev->val,curr->val);
        return head;
    }
};
