class Solution {
public:

    //use 2 pointer appraoch as , place i pointer on the 1 and another at the 2 element of the array 
    //than move 1-1 to the next elements 
    //i will take care for the even indices and odd will be taken care by j 
    //if they are not according to there requirements than just swap the elements 
    //increament the pointers by +2

    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0;
        int j=1;
        int n = nums.size();
        while(i<n && j<n)
        {
            if(nums[i] % 2 ==0) i+=2;
            else if(nums[j] % 2 == 1) j+=2;
            else {
                swap(nums[i],nums[j]);
                j+=2;
                i+=2;
            }
        }
        return nums;
    }
};
