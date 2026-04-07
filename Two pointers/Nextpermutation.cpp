class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //algoritm k 3 steps hai 
        //find out the dip from the back 
        //swap the element that is slightly greater than the ind 
        //reverse all the elements that are after right 

        int ind = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind=i;
                break;
            }
        }
        if(ind == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        //else mtlb ki milgya hia 
        for(int i =n-1;i>=0;i--)
        {
            if(nums[ind] < nums[i]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
        return ;
    }
};
