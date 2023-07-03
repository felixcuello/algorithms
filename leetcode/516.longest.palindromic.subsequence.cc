/*
 dp[a,b] = "Is the longest palindromic subsequence between a and b"
 f(s, dp, a, b)
    if b < a => return 0
    if a == b => return 1
    if s[a] == s[b] => 2 + f(s, dp, a+1, b-1)
    else max(f(s,dp,a+1,b), f(s,dp,a,b-1))
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int f(string&s, vector<vector<int> >& dp, int a, int b) {
    if(b < a) return 0;
    if(a == b) return 1;
    if(dp[a][b] != -1) return dp[a][b];

    if(s[a] == s[b]) {
      dp[a][b] = 2 + f(s, dp, a+1, b-1);
    } else {
      dp[a][b] = max(f(s, dp, a+1, b), f(s, dp, a, b-1));
    }

    return dp[a][b];
  }

  int longestPalindromeSubseq(string s) {
    int sl = s.length() - 1;
    vector<vector<int> > dp;
    for(int i=0; i<=sl; i++) {
      vector<int> temp;
      for(int j=0; j<=sl; j++)
        temp.push_back(-1);
      dp.push_back(temp);
    }

    return f(s, dp, 0, sl);
  }
};

int main() {
  string s; cin >> s;
  Solution *sol = new Solution();
  cout << sol->longestPalindromeSubseq(s) << endl;
}
