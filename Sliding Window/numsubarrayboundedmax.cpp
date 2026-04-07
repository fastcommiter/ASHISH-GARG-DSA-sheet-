class Solution {
public:
    int helper(vector<int>&nums,int target)
    {
        int l =0;
        int cnt =0;
        int len =0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r] <= target)
            {
                len++;
            }
            else{
                len=0;
                //break hogya hai flow;
            }
            cnt+=len;
        }
        return cnt;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       return helper(nums,right) - helper(nums,left-1);

    }
};
