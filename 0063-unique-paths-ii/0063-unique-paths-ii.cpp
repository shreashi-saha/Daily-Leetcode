class Solution {
private:
    int move(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0 || matrix[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        int up = move(i-1, j, matrix, dp);
        int left = move(i, j-1, matrix, dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return move(m-1, n-1, obstacleGrid, dp);
    }
};