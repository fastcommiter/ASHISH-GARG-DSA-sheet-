class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        //now i have 1--3 2--2 3--1
        //hume chaia woh jinki freuency jydi hai dusro s 
        //have the markings of the occurence than kya kro ki unko frequency wise apne min heap mi daldo 
        //if size of the queue is greater than k to kya kro ki just pop out the elements 
        //once done iterte through the queue and make the nesseccary detailings


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(auto i : mp)
        {
            int num = i.first;
            int freq = i.second;
            pq.push({freq,num});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty())
        {
            auto [f,n] = pq.top();
            pq.pop();
            ans.push_back(n);
        }
        return ans;
    }
};
