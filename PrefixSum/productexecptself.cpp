class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] * nums[i];
        }
        for(int i =n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1] * nums[i];
        }

        for(int i =0;i<n;i++){
            int lp =1,rp=1;
            if(i>0) lp = prefix[i-1];
            if(i<n-1) rp = suffix[i+1];

            ans[i] = lp*rp;
        }
        return ans;
    }
};
