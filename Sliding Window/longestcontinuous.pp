class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //since length deni hai to what matters is r and l 
        int l=0;
        int maxlen =0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        multiset<int> window;
        for(int r=0;r<nums.size();r++)
        {
            window.insert(nums[r]);
            while(*window.rbegin() - *window.begin() > limit)
            {
                window.erase(window.find(nums[l]));
                l++;
            }
            //agr window valid hai to kya kro is calculate the length 
            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
