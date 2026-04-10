class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //since next grater tdekhna hai to hum strt krenge r->l 
        //since it is a circular array to 2 bar traversal hume answer dedega
        
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            ans[i]=st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            ans[i]=st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};
