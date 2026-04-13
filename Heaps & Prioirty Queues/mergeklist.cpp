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
    //so is question kya hai mtlb hume kya krna hai sari list ko merge krna hai into a new list 
    //or wo list sorted honi chaia 
    //whats the approach 
    //phele har node k phela element daldo aaek min heap mai 
    //jo sbse chota hai use use kro add kro agr
    //uske agr koi or node hai touse push krdo us pq mai 
    //AGR WO VALUE NULL NI HAI TO TABHI TO PUSH KROGE NA 
    //to wohi catch hai fil krte time dekhna hai kya yh non null hai tabhi fill krna

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        int n = lists.size();
        priority_queue<tuple<int,ListNode*>,vector<tuple<int,ListNode*>>,greater<>>pq;
        for(int i=0;i<n;i++)
        {
            if(lists[i]!=nullptr)  pq.push({lists[i]->val,lists[i]});
        }
        //humne kya kra hai har list k phela node daldiya hai bs ab unhe process krdo 
        while(!pq.empty())
        {
            auto [v,node] = pq.top();
            pq.pop();
            if(head == nullptr)
            {
                //mtlb abhi tk koi node ni ayi hai 
                head = node;
                tail = node;
                //first node assign hogyi hai 
            }
            else{
                //mtlb ki second node hai 
                tail->next = node;
                tail = node;
                //ab us hi node ko tail assign krdo
            }
            //ab dekho kya uske age koi or node hai 
            if(node -> next !=NULL)
            {
                pq.push({node->next->val,node->next});
            }
        }
        return head;
    }
};
