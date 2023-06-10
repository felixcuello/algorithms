#include <iostream>
#include <map>
#include <vector>
#include <map>

using namespace std;

/*
 * dp[row][col] : "The best possible square that finishes in row,col"
 *
 *
 */

class Solution {
  public:
    int f(int row, int col, vector<vector<char> >& matrix, vector<vector<int> >&dp, int *max) {
      if(row < 0 || col < 0) return 0;
      if(dp[row][col] != -1) return dp[row][col];

      int a = f(row-1, col, matrix, dp, max);
      int b = f(row, col-1, matrix, dp, max);
      int c = f(row-1, col-1, matrix, dp, max);

      if(matrix[row][col] == '0') {
        dp[row][col] = 0;
      } else {
        dp[row][col] = 1 + min(min(a,b),c);
      }

      if(dp[row][col] > *max) *max = dp[row][col];

      return dp[row][col];
    }

    int maximalSquare(vector<vector<char> >& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();
      vector<vector<int> > dp;

      for(int row=0; row<rows; row++) {
        vector<int> temp;
        for(int col=0; col<cols; col++)
          temp.push_back(-1);
        dp.push_back(temp);
      }

      int max = 0;
      f(rows-1, cols-1, matrix, dp, &max);

      return max*max;
    }
};

int main() {
  int rows; cin >> rows;
  int cols; cin >> cols;

  vector<vector<char> > matrix;

  for(int row=0; row<rows; row++) {
    vector<char> temp;
    for(int col=0; col<cols; col++) {
      char c; cin >> c;
      temp.push_back(c);
    }
    matrix.push_back(temp);
  }

  Solution *s = new Solution();
  cout << s->maximalSquare(matrix);

  return 0;
}
