class Solution {
public:
  void sink(vector<vector<char>>& board, int row, int col) {
    if(row < 0) return;
    if(row >= board.size()) return;
    if(col < 0) return;
    if(col >= board[0].size()) return;
    if(board[row][col] != 'X') return;
    
    board[row][col] = '.';
    sink(board, row-1, col);
    sink(board, row+1, col);
    sink(board, row, col-1);
    sink(board, row, col+1);
  }
  
  int countBattleships(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    int ans = 0;
    for(int row=0; row<rows; row++)
      for(int col=0; col<cols; col++)
        if(board[row][col] == 'X') {
          sink(board, row, col);
          ans++;
        }
    return ans;
  }
};

/*
IDEA: O(m * n)

We look for "X" in the board.

1. Every time we find an "X" we add 1 to the answer
2. We sink the ship changing the "X" to other character (using DFS)

*/
