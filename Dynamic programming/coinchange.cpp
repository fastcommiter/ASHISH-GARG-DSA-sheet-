class Solution {
public:

    int helper(int i ,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        //base case 
        //agr mai 0 index mai hu to kya dunga remainig / coin[i]
        if(i==0)
        {
            if(amount % coins[i] == 0)  return amount/coins[0];
            else return 1e9;
        }

        if(dp[i][amount] != -1) return dp[i][amount];
        //ab possibilites 
        //agr mai take krunga to merpe coin + 1 hoga 
        int take =1e9,untake =1e9;
        if(coins[i] <= amount)
        {
            take = 1 + helper(i,amount-coins[i],coins,dp);
        }
        untake = 0 + helper(i-1,amount,coins,dp);

        return dp[i][amount] = min(take,untake);
    }
    int coinChange(vector<int>& coins, int amount) {
        //infinte hai to kya scene hai agr take kre hai to mtlb hum kitne bhi leskte hai 
        //strt kro last index s 
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp) == 1e9 ? -1 : helper(n-1,amount,coins,dp);
    }
};
