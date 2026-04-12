class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //hume bus chote cost wale ice creams ko use krna hai pehele 
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto i : costs)
        {
            pq.push(i);
        }
        int cnt =0;
        //push krdi hai cost , ab sbse age sbse choti cost hogi use process krlo 
        while(!pq.empty() && coins>0)
        {
            if(pq.top() <= coins)
            {
                coins -= pq.top();
                cnt++;
            }
            pq.pop();
        }
        return cnt;
    }
};
