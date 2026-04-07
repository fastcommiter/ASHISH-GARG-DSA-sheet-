class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //hume bus find krna hai longest subarray jisme 1 hi rehte hai bs 
        int maxlen = INT_MIN;
        int cnt =0;
        for(int r =0;r<nums.size();r++)
        {
            if(nums[r] == 1)
            {
                cnt++;    
            }
            else
            {
                //agr zero hai to kya kro ki mark zero 
                cnt=0;
            }
            maxlen = max(maxlen,cnt);
        }
        return maxlen;
    }
};
