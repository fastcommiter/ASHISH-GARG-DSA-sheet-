class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>dp(n,vector<int>(m));
        vector<vector<int>>dp2(n,vector<int>(m));
        //make it a possible block matriz 
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                dp[i][j] = mat[i][j];

                if(i>0)
                {
                    dp[i][j] += dp[i-1][j];
                }
                if(j>0)
                {
                    dp[i][j] += dp[i][j-1];
                }
                if(j>0 && i>0)
                {
                    dp[i][j] -= dp[i-1][j-1];
                }
            }
        }
        //mera prefix ready hai 
        //ab hume new new r or c calculte krna hai 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //ab kya krn hai 
                //for every r and c hume new r1c1 or r2r2 calculate krna hai 

                int r1 = max(0,i-k);
                int c1 = max(0,j-k);

                int r2 = min(n-1,i+k);
                int c2 = min(m-1,j+k);  

                dp2[i][j] = dp[r2][c2];

                if(r1 > 0)
                {
                    dp2[i][j] -= dp[r1-1][c2];
                }    
                if(c1 > 0)
                {
                    dp2[i][j] -= dp[r2][c1-1];
                }
                if(c1 >0 && r1 > 0)
                {
                    dp2[i][j] += dp[r1-1][c1-1];
                }
            }
        }
        return dp2;
    }
};
