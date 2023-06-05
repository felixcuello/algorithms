#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define mp(a,b) make_pair(a,b)

class Solution {
  public:
    int f(int row, int col, int rows, int cols, vector<vector<int> >& m, map<pair<int,int>, int>& dp) {
      if(dp.find(mp(row,col)) != dp.end()) return dp[mp(row,col)];
      if(col < 0 || col > cols) return 100000;

      dp[mp(row,col)] = m[row][col];

      if(col == 0)
        dp[mp(row,col)] += min(f(row+1, col, rows, cols, m, dp), f(row+1, col+1, rows, cols, m, dp));
      else if(col == cols)
        dp[mp(row,col)] += min(f(row+1, col-1, rows, cols, m, dp), f(row+1, col, rows, cols, m, dp));
      else
        dp[mp(row,col)] += min(
            min(f(row+1, col, rows, cols, m, dp), f(row+1, col+1, rows, cols, m, dp)),
            f(row+1, col-1, rows, cols, m, dp)
            );

      return dp[mp(row,col)];
    }

    int minFallingPathSum(vector<vector<int> >& matrix) {
      map<pair<int,int>, int> dp;
      int rows = matrix.size();
      int cols = matrix[0].size();

      for(int col=0; col<cols; col++)
        dp[mp(rows-1, col)] = matrix[rows-1][col];

      int min = 101*101;
      for(int col=0; col<cols; col++) {
        int temp = f(0, col, rows-1, cols-1, matrix, dp);
        if(temp < min) min = temp;
      }

      return min;
    }
};


int main() {
  int rows; cin >> rows;
  int cols; cin >> cols;

  vector<vector<int> > matrix;
  for(int row=0; row<rows; row++) {
    vector<int> temp;
    for(int col=0; col<cols; col++) {
      int e; cin >> e;
      temp.push_back(e);
    }
    matrix.push_back(temp);
  }

  Solution* s = new Solution();
  cout << s->minFallingPathSum(matrix);
  return 0;
}
