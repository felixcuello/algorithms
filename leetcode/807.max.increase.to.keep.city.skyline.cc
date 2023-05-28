class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    // find maximums for sides skylines
    vector<int> north_south(cols);
    vector<int> east_west(rows);
    
    for(int row=0; row<rows; row++) {
      for(int col=0; col<cols; col++) {
        if(north_south[col] < grid[row][col])
          north_south[col] = grid[row][col];
        
        if(east_west[row] < grid[row][col])
          east_west[row] = grid[row][col];
      }
    }
    
    // find the answer :-D
    int ans = 0;
    for(int row=0; row<rows; row++) {
      for(int col=0; col<cols; col++) {
              ans += min(north_south[col], east_west[row]) - grid[row][col];
        cout 
          << grid[row][col] << ' '
          << '[' << min(north_south[col], east_west[row]) << ']' << ' ';
        // ans += max(north_south[col], east_west[row]) - min(north_south[col], east_west[col]);
      }
      cout << '\n';
    }
    
    return ans;
  }
};

/*
Idea:

The skyline is defined by the tallest building of each row or col.

East/West and North/South are basically the same skyline.

=> Once we have calculated the maximum height of each row/col
=> The result is something like 

->  ans = SUM(min(east_west[col], north_south[row]))
*/
