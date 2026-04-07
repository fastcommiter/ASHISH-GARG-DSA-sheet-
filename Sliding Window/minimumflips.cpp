class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt =0;
        int n=nums.size();
        
        //iterate from i=0
        //then go till n-3
        //just make sure to check for the  nums[i] == 0 than just cnt++ and make sure to rotate the two numbers 
        //xoring them with 1

        for(int i=0;i<=n-3;i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
                nums[i] = 1;
                nums[i+1]^=1;
                nums[i+2]^=1;
            }
        }
        if(nums[n-1] == 1 && nums[n-2] == 1) return cnt;
        return -1;
    }
};
