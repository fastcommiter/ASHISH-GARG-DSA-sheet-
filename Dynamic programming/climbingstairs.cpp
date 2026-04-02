class Solution {
public:

    int helper(int i ,vector<int> &cost,vector<int> &dp)
    {
        int n = cost.size();
        if(i == n) return 0;
        //base case banenge ki agr mai last mai agya 
        if(i == n-1) return cost[i];

        if(dp[i] != -1) return dp[i];

        //possibilites
        int take =1e9;
        int onestep = cost[i] + helper(i+1,cost,dp);
        int twostep = cost[i] + helper(i+2,cost,dp);
        return dp[i] = min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // either 1 ya 2 steps lekste hai to 
        // function bano ki kya fir n-1 ya n-2 mai min cost deni hai 
        //cost kya hogi always price[i] + helper(i-1,prices)
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(helper(0,cost,dp),helper(1,cost,dp));
    }
};
