class Solution {
public:

    int helper(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size();


        if(i == n-1 && j == m-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        //possibilites
        int right = 1e9;
        int down = 1e9;
        if(i+1 < n) down = helper(i+1,j,grid,dp);
        if(j+1 < m) right = helper(i,j+1,grid,dp);

        return dp[i][j] = grid[i][j] + min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,grid,dp);
    }
};
