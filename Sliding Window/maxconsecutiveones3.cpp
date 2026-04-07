class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //find the longest subarry with ost k zeros 
        int l =0;
        int maxlength = INT_MIN;
        int cnt =0;
        for(int r=0;r<nums.size();r++)
        {
            //pheli chiz 
            if(nums[r] == 0) cnt++;

            while(cnt > k)
            {
                if(nums[l] == 0)
                {
                    cnt--;
                }
                l++;
            }
            maxlength = max(maxlength,r-l+1);
        }
        return maxlength;
    }
};
