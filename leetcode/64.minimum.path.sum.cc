#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define mp(a,b) make_pair(a,b)

class Solution {
  public:
    int f(vector<vector<int> >&grid, map<pair<int, int>, int>& dp, int row, int col) {
      if(dp.find(mp(row, col)) != dp.end()) return dp[mp(row, col)];

      dp[mp(row,col)] += grid[row][col] + min(f(grid, dp, row-1, col), f(grid, dp, row, col-1));

      return dp[mp(row,col)];
    }

      int minPathSum(vector<vector<int> >& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        map<pair<int,int>, int> dp;

        for(int r=0; r<rows; r++)
          for(int c=0; c<cols; c++)
            if(r == 0 && c == 0)
              dp[mp(0,0)] = grid[0][0];
            else if(r == 0)
              dp[mp(0, c)] += dp[mp(0,c-1)] + grid[0][c];
            else if(c == 0)
              dp[mp(r, 0)] += dp[mp(r-1,0)] + grid[r][0];

        return f(grid, dp, rows-1, cols-1);
      }
};

/*
 * dp[r,c] : "The minimum path we can use to reach the position [r,c]"
 *
 * dp[r,0] = grid[r, 0]
 * dp[0,c] = grid[0, c]
 *
 * dp[r,c] = min(dp[r-1,c], dp[r,c-1])
 *
 */


int main() {
  int rows; cin >> rows;
  int cols; cin >> cols;
  vector<vector<int> > grid;

  for(int row=0; row<rows; row++) {
    vector<int> temp;
    for(int col=0; col<cols; col++) {
      int e; cin >> e;
      temp.push_back(e);
    }
    grid.push_back(temp);
  }

  Solution* s = new Solution();
  cout << s->minPathSum(grid);
  return 0;
}


/*
 * dp[row,col] : "The minimum sum path up to the cell [row,col]"
 *
 * dp[row, 0] : grid[row, 0]
 * dp[0, col] : grid[0, col]
 * dp[row, col] = grid[row, col] + min(dp[row-1,col], dp[row, col-1])
 *
 */
