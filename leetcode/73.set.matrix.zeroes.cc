class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();
      bool wipe_first_row = false;
      bool wipe_first_col = false;
      
      for(int col=0; col<cols; col++)
          wipe_first_row |= matrix[0][col] == 0;
      for(int row=0; row<rows; row++)
          wipe_first_col |= matrix[row][0] == 0;
      
      for(int row=1; row<rows; row++)
        for(int col=1; col<cols; col++)
          if(matrix[row][col] == 0) {
            matrix[row][0] = 0;
            matrix[0][col] = 0;
          }
      
      for(int row=1; row<rows; row++)
        if(matrix[row][0] == 0)
          for(int col=0; col<cols; col++)
            matrix[row][col] = 0;
      
      for(int col=1; col<cols; col++)
        if(matrix[0][col] == 0)
          for(int row=0; row<rows; row++)
            matrix[row][col] = 0;
      
      if(wipe_first_row)
        for(int col=0; col<cols; col++)
          matrix[0][col] = 0;
      
      if(wipe_first_col)
        for(int row=0; row<rows; row++)
          matrix[row][0] = 0;
    }
};
