class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        for(auto i : bookings)
        {
            int lower = i[0]-1;
            int upper = i[1]-1;

            int w = i[2];
            for(int j =lower;j<=upper;j++)
            {
                ans[j] += w;
            }
        }
        return ans;
    }
};
