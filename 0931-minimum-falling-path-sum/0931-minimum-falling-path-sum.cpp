class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int j=0;j<n;j++)
        {
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                
                int upleft = matrix[i][j];
                if(j-1>=0) upleft += dp[i-1][j-1];
                else upleft += 1e9;

                int upright = matrix[i][j];
                if(j+1 < n) upright += dp[i-1][j+1];
                else upright += 1e9;

                dp[i][j] = min(up, min(upleft, upright));
            }
        }

        for(int j=0;j<n;j++)
        {
            mini = min(mini, dp[m-1][j]);
        }
        return mini;
    }
};