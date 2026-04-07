class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l =0;
        int maxsum=0;
        int sum =0;
        unordered_map<int,int>mp;
        for(int r=0;r<nums.size();r++)
        {
            mp[nums[r]]++;
            sum+=nums[r];

            while(mp[nums[r]] > 1)
            {
                mp[nums[l]]--;
                sum-=nums[l];
                if(mp[nums[l]] == 0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            //agr  iske neche aya hai to mtlb yh valid hai windoe 
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
};
