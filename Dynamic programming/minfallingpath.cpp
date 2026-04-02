class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        if(n==1 && m==1) return matrix[0][0];

        vector<vector<int>>dp(n,vector<int>(m,0));
        int mini = INT_MAX;

        for(int i = 0;i<m;i++)
        {
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i = n-2;i>=0;i--)
        {
            for(int j =0;j<m;j++)
            {
                int left=1e9,right=1e9,down=1e9;

                if(i+1 < n) down = dp[i+1][j];
                if(i+1 < n && j+1 < m) right = dp[i+1][j+1];
                if(i+1 < n && j-1 >= 0) left = dp[i+1][j-1];

                dp[i][j] = matrix[i][j] + min({down,right,left});
            }
        } 
        for(int i=0;i<m;i++)
        {
            int cost = dp[0][i];
            mini = min(mini,cost);
        }

        return mini;
    }
};
