#define mp(a,b) make_pair(a,b)

class Solution {
public:
  int f(int rows, int cols, vector<vector<int>>& dp) {
    if(dp[rows][cols] != -1) return dp[rows][cols];

    dp[rows][cols] = f(rows-1, cols, dp) + f(rows, cols-1, dp);
    return dp[rows][cols];
  }

  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    vector<vector<int>> dp;
    for(int row=0; row<rows; row++) {
      vector<int> temp;
      for(int col=0; col<cols; col++)
        temp.push_back(-1);
      dp.push_back(temp);
    }

    for(int row=0; row<rows; row++)
      for(int col=0; col<cols; col++)
        if(col == 0 && row == 0)
          dp[row][col] = obstacleGrid[row][col] ? 0 : 1;
        else if(obstacleGrid[row][col])
          dp[row][col] = 0;
        else if(col == 0)
          dp[row][col] = dp[row-1][col];
        else if(row == 0)
          dp[row][col] = dp[row][col-1];
        else
          dp[row][col] = -1;

    return f(rows-1, cols-1, dp);
  }
};

