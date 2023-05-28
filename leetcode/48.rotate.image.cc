class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int ms = matrix.size();
    
    // 1. Transpose matrix
    for(int row=0; row<ms; row++) {
      for(int col=0; col<row; col++) {
        int temp = matrix[row][col];
        matrix[row][col] = matrix[col][row];
        matrix[col][row] = temp;
      }
    }
    
    // 2. Swap columns
    int a = 0;
    int b = ms - 1; // since it's n x n matrix I can take rows
    while(a < b) {
      for(int row=0; row<ms; row++) {
        int temp = matrix[row][a];
        matrix[row][a] = matrix[row][b];
        matrix[row][b] = temp;
      }
      a++;
      b--;
    }
  }
};

/*

IDEA

There's a clever idea to do this (I looked it up a long time ago and never forgot).

The way to rotate a matrix clockwise without having to allocate more memory is to do this simple algorithm:

1. Transpose the matrix using col[i] == row[i] diagonal as hinge/pivot
    ^^^^^ You have to be CARFUL on this step. Because transposition has to be computed only HALF of the matrix (when you do it in place)
    otherwise you will get a symmetric matrix, that's why the second loop goes up to col<row on line 8
    
2. Swap the columns col[i] == col[n-i-1] until (i >= n-i-1)

*/
