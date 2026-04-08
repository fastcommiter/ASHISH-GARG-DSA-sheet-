class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n = nums.size();
        vector<long long>prefix(n);
        prefix[0] = nums[0];
        for(int i =1;i<n;i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }
        vector<long long>suffix(n);
        suffix[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1] + nums[i];
        }
        int i =0 ;
        long long cnt =0;
        while(i<n-1)
        {
            if(prefix[i] >= suffix[i+1])
            {
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};
