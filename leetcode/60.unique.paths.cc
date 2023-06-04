#include <bits/stdc++.h>

using namespace std;

#define mp(a,b) make_pair(a,b)
#define ull unsigned long long

class Solution {
  public:
    ull f(ull rows, ull cols, map<pair<ull,ull>, ull>& dp) {
      if(rows == 0) return 1;
      if(cols == 0) return 1;
      if(dp.find(mp(rows,cols)) != dp.end()) return dp[mp(rows,cols)];

      dp[mp(rows,cols)] = f(rows-1, cols, dp) + f(rows, cols-1, dp);
      return dp[mp(rows,cols)];
    }

    ull uniquePaths(ull rows, ull cols) {
      map<pair<ull,ull>, ull> dp;
      for(ull i=0; i<cols; i++) dp[mp(0,i)] = 1;
      for(ull i=0; i<rows; i++) dp[mp(i,0)] = 1;

      f(rows, cols, dp);
      return dp[mp(rows-1,cols-1)];
    }
};

ull main() {
  ull rows; cin >> rows;
  ull cols; cin >> cols;

  Solution* s = new Solution();
  cout << s->uniquePaths(rows, cols) << '\n';
  return 0;
}

/*
 * dp[rows,cols]  = "The number of ways you can reach [row,col]"'
 *
 * dp[0,col] = 1  // base case
 * dp[row,0] = 1  // base case
 * dp[row, col] = dp[row-1,col] + dp[row, col-1]
 *
 */
