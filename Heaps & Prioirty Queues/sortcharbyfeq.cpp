class Solution {
public:
    string frequencySort(string s) {
        //sare elemntss ki frequncy store krlo 
        unordered_map<char,int>mp;
        for(int i =0;i<s.size();i++)
        {
            char ch = s[i];
            mp[ch]++;
        }
        //ab maxheap mai sb process krdo 
        priority_queue<pair<int,char>>pq;
        for(auto i : mp)
        {
            int freq = i.second;
            char ch = i.first;

            pq.push({freq,ch});
        }
        string ans ="";
        while(!pq.empty())
        {
            auto [ freq,ch ] = pq.top();
            pq.pop();
            while(freq--)
            {
                ans+=ch;
            }
        }
        return ans;
    }
};
