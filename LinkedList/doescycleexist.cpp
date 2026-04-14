class Solution {
public:

    //cycle detection is figure out with slow and fast pointer as 
    //phele agr dono match hogye to break kro 
    //aaek ko wps s strt mai dalo and move both of them with equal pase
    //ise kyya hoga jo strt mai hoga wo start to start of cycle tk k distance pura karega or dusra wala 
    //kya krega wo puri cycle k aaek round krke aega 

    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};
