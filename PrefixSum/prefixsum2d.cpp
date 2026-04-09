class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n = mat.size();
        int m =mat[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m));
        dp[0][0] = mat[0][0];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j] = mat[i][j];
                
                if(i > 0)
                {
                    dp[i][j] += dp[i-1][j];
                }
                if(j > 0)
                {
                    dp[i][j] += dp[i][j-1];
                }
                if(i>0 && j> 0)
                {
                    dp[i][j] -= dp[i-1][j-1];
                }
            }
        }
        vector<int>ans;
        for(auto i : queries)
        {
            int r1 = i[0];
            int c1 = i[1];
            int r2 = i[2];
            int c2 = i[3];
            
            /*
                    0 0 0 0 0
                    0 1 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0 
                    0 0 0 0 1
            */
            int sum = dp[r2][c2];
            if(c1-1 >= 0)
            {
                sum -= dp[r2][c1-1];
            }
            if(r1-1 >= 0)
            {
                sum -= dp[r1-1][c2];
            }
            if(r1-1 >= 0 && c1-1 >= 0)
            {
                sum += dp[r1-1][c1-1];            
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
