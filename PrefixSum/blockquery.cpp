class NumMatrix {
    public:
    vector<vector<int>> dp = vector<vector<int>>(210, vector<int>(210)); 

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i > 0)
                {
                    matrix[i][j] += matrix[i-1][j];
                }
                if(j>0)
                {
                    matrix[i][j] += matrix[i][j-1];
                }
                if(i>0 && j>0)
                {
                    matrix[i][j] -= matrix[i-1][j-1];
                }
            }
        }
        dp = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum = dp[row2][col2];
        if(row1>0)
        {
            sum-=dp[row1-1][col2];
        }
        if(col1>0)
        {
            sum-=dp[row2][col1-1];
        }
        if(col1>0 && row1>0)
        {
            sum+=dp[row1-1][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
