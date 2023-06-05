#define mp(a,b) make_pair(a,b)

class Solution {
public:
  int f(int row, int col, vector<vector<int>>& t, map<pair<int,int>, int>& dp) {
    if(dp.find(mp(row,col)) != dp.end()) return dp[mp(row,col)];

    dp[mp(row,col)] = t[row][col] + min(f(row+1, col, t, dp), f(row+1, col+1, t, dp));
    return dp[mp(row,col)];
  }

  int minimumTotal(vector<vector<int>>& triangle) {
    int rows = triangle.size();
    int last_cols = triangle[rows-1].size();

    map<pair<int,int>,int> dp;
    for(int col=0; col<last_cols; col++)
      dp[mp(rows-1, col)] = triangle[rows-1][col];
    
    return f(0, 0, triangle, dp);
  }
};
