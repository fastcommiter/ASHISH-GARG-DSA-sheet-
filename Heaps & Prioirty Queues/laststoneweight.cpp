class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //heaviest 2 stones mtlb its a maxheap problem 
        priority_queue<int>pq;
        for(auto i : stones) 
        {
            pq.push(i);
        }
        //ab isme push krdiye hai humne sare stones 
        while(pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            //agr same weight hai to destroy
            if(a!=b)
            {
                pq.push(abs(a-b));
            }
            else pq.push(0);
        }
        return pq.top();
    }
};
