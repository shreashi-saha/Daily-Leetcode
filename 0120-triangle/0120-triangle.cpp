class Solution {
private:
    int move(vector<vector<int>>& triangle, int n, vector<vector<int>>& dp)
    {
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0;j--)
            {
                int up = triangle[i][j] + dp[i+1][j];
                int upleft = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(up, upleft);
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return move(triangle, n, dp);
    }
};