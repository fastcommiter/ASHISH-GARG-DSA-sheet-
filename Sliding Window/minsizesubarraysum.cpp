class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //length of subarray whose sum is greater than or equal to target
        int l=0;
        int sum=0;
        int minlength = INT_MAX;
        for(int r=0;r<nums.size();r++)
        {
            sum+=nums[r];

            //shrink kro or len bhi update krdo 
            while(sum >= target)
            {
                minlength = min(minlength,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return minlength == INT_MAX ? 0 : minlength;
    }
};
