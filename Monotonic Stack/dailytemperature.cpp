class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //number of  days u need to wait in order to get that day when i can find the warmer day
        //warmer mtlb tumhe bada element chaia next
        //kitne din rukna is equal to what indexing 
        //to mtlb hum indexes store krenge isme monotnic stack mai fir fill krte time 
        //well just find the diffrences among the i and next[i]
        int n = temperatures.size();
        vector<int>next(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            next[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        vector<int>ans(n);
        for(int i =0;i<n;i++)
        {
            if(next[i] == -1)
            {
                ans[i] = 0;
            }
            else{
                ans[i] = next[i] - i;
            }
        }
        return ans;
    }
};
