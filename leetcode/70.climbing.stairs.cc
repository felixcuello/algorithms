class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n+2);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++)
      dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
  }
};

/*
IDEA

If "." is a jump of size 1, and "-" is a jump of size 2

Then reaching each floor is something like this

1 . => 1 way
2 .. / - => 2 ways
3 ... / .- / -. => 3 ways
4 .... / -- / -.. / .-. / ..- => 5 ways
n => dp[n-1] + dp[n-2]

*/
