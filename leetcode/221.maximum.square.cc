#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * dp[row,col] : "The maximum side of a square I can form from (row,col)"'
 *
 * BASE CASES
 * f(rows, col) = 0
 * f(row, cols) = 0
 *
 * RECURRENCE
 * f(row,col) = if(vert(row,col) && horiz(row,col))
 *                1 + f(row+1,col+1)
 *              else
 *                0
 *              end
 */

class Solution {
public:
  int f(int row, int col, vector<vector<char> >&matrix, vector<vector<int> >& dp) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if(row == rows || col == cols) return 0;     // base case
    if(dp[row][col] != -1) return dp[row][col];  // memoized

    int horizontal = 0;
    for(int c=col; c<min(rows,cols); c++) if(matrix[row][c] == '1') horizontal++; else break;

    int vertical = 0;
    for(int r=row; r<min(rows,cols); r++) if(matrix[r][col] == '1') vertical++; else break;

    dp[row][col] = matrix[row][col] == '1';

    if( (horizontal == (min(rows,cols) - col)) && (vertical == (min(rows,cols) - row))) {
      cout << "row=" << row << " col=" << col << endl;
      dp[row][col] += f(row+1, col+1, matrix, dp);
    }

    return dp[row][col];
  }

  int maximalSquare(vector<vector<char> > &matrix) {
    vector<vector<int> > dp;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int row=0; row<rows; row++) {
      vector<int> temp;
      for(int col=0; col<cols; col++)
        temp.push_back(-1);
      dp.push_back(temp);
    }

    int result = 0;
    for(int row=0; row<rows; row++) {
      for(int col=0; col<cols; col++) {
        int temp = f(row, col, matrix, dp);
        if(temp > result) result = temp;
      }
    }


    return result * result;
  }
};

int main() {
  Solution *s = new Solution();
  int rows;
  cin >> rows;
  int cols;
  cin >> cols;
  vector<vector<char> > matrix;

  for (int row = 0; row < rows; row++) {
    vector<char> temp;
    for (int col = 0; col < cols; col++) {
      char e; cin >> e;
      temp.push_back(e);
    }
    matrix.push_back(temp);
  }

  cout << s->maximalSquare(matrix);

  return 0;
}

/*
 * dp[r,c,s] : "I can get a square of size s from r,c"
 *
 * dp[r][c][1] : matrix[r][c]
 * dp[r][c][s] : horiz_ones(r,c,s) && vert_ones(r,c,s) && dp[r][c][s-1]
 *
 */




