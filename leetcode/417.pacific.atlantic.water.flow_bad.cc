#define PACIFIC 1
#define ATLANTIC 2

class Solution {
public:
  void print_ocean(vector<vector<int>> o) {
    int rows = o.size();
    int cols = o[0].size();
    for(int row=0; row<rows; row++) {
      for(int col=0; col<cols; col++) {
        cout << o[row][col] << " ";
      }
      cout << endl;
    }
  }

  bool dfs(vector<vector<int>>& heights, int row, int col, vector<vector<int>>& o, int towards, vector<vector<bool>>& visited) {
    if(o[row][col] >= 0) return o[row][col];
    if(visited[row][col]) return 0; // we already visited that one

    visited[row][col] = true; // mark as visited

    o[row][col] = 0;

    if(row == 1 && col == 2) {
      cout << "ocean = " << towards << endl;
      cout << "PRE value = " << o[row][col] << endl;
    }

    if(heights[row][col] >= heights[row-1][col]) o[row][col] |= dfs(heights, row-1, col, o, towards, visited);
    if(heights[row][col] >= heights[row+1][col]) o[row][col] |= dfs(heights, row+1, col, o, towards, visited);
    if(heights[row][col] >= heights[row][col-1]) o[row][col] |= dfs(heights, row, col-1, o, towards, visited);
    if(heights[row][col] >= heights[row][col+1]) o[row][col] |= dfs(heights, row, col+1, o, towards, visited);

    visited[row][col] = false; // mark as not visited
    
    if(row == 1 && col == 2) {
      cout << "POS value = " << o[row][col] << endl;
    }

    return o[row][col];
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights.size();

    vector<vector<int>> pa(rows+2, vector<int>(cols+2, -1)); // flows to the pacific
    vector<vector<int>> at(rows+2, vector<int>(cols+2, -1)); // flows to the atlantic
    vector<vector<int>> h(rows+2, vector<int>(cols+2, -1)); // expanded heights matrix
    vector<vector<bool>> visited(rows+2, vector<bool>(cols+2, false)); // expanded heights matrix

    for(int row=0; row<rows+2; row++) {
      for(int col=0; col<cols+2; col++) {
        pa[0][col] = 1;
        at[0][col] = 0;
        at[rows+1][col] = 1;
        pa[rows+1][col] = 0;
      }
      at[row][cols+1] = 1;
      pa[row][cols+1] = 0;
      pa[row][0] = 1;
      at[row][0] = 0;
    }

    for(int row=1; row<rows+1; row++)
      for(int col=1; col<cols+1; col++)
        h[row][col] = heights[row-1][col-1];
    
    at[rows+1][0] = 1;
    pa[rows+1][0] = 0;
    pa[0][cols+1] = 1;
    at[0][cols+1] = 0;

    vector<vector<int>> ans;

    for(int row=1; row<rows+1; row++)
      for(int col=1; col<cols+1; col++) {
        pa[row][col] = dfs(h, row, col, pa, PACIFIC, visited);
        at[row][col] = dfs(h, row, col, at, ATLANTIC, visited);
      }
    
    cout << "pacific" << endl;
    print_ocean(pa);
    cout << "atlantic" << endl;
    print_ocean(at);
    
    for(int row=1; row<rows+1; row++)
      for(int col=1; col<cols+1; col++)
        if(pa[row][col] > 0 && at[row][col] > 0)
          ans.push_back({row-1, col-1});
    
    return ans;
  }
};

