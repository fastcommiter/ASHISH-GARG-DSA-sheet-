class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //mtlb jo k sbse jyda bar ae hai wese elements dedo 
        //phele sbki frequency lelo 
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        //sbse jyda bar ae hai to kya lenge min heap 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(auto i : mp)
        {
            int num = i.first;
            int freq = i.second;

            pq.push({freq,num});
            if(pq.size() > k) pq.pop();
        }

        //ab kya kro jo elements usme hai unhe mark down krdo 
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
