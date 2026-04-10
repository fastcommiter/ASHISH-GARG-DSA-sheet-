class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt =0;
        int  sum =0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int r = sum % k;
            if(r == 0) cnt+=1;
            if(r < 0) r+=k;

            if(mp.find(r) != mp.end())
            {
                cnt += mp[r];
            }
            mp[r] ++;
        }
        return cnt;
    }
};
