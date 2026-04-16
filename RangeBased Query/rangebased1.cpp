class NumArray {
public:

    //odea is ki agr hum prefix sum k topic in head rkhre hai to main logic yh hai ki 
    //since hume sum based range qurey use krne k liye we have to make sure ki kya kre hum 
    //hum koi bhi given range k liye arr[right] - arr[left-1] krte hai 
    //agr isme range hai 1,9 to hojeag arr[9] - arr[0]
    //agr query di hai about 0,9 to -1 chle jaga 
    //to kya kro ki jo prefix calcute krne k lye array banoge use tum 
    //+1 size k banao or kya kroge ki 
    //strt kroge i = 1 s bharna 
    vector<int>a;
    NumArray(vector<int>& nums) {
        a.resize(nums.size() + 1);
        for(int i=0;i<nums.size();i++)
        {
            a[i+1] = a[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return a[right+1] - a[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
