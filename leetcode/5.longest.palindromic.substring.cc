#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool f(int a, int b, string &s, vector<vector<int>> &dp) {
    if (a == b)
      return true;
    if (a + 1 == b)
      return s[a] == s[b];
    if (dp[a][b] != -1)
      return dp[a][b];

    dp[a][b] = (s[a] == s[b]) && f(a + 1, b - 1, s, dp);

    return dp[a][b];
  }

  string longestPalindrome(string s) {
    int ss = s.size();
    vector<vector<int>> dp;
    for (int a = 0; a < ss; a++) {
      vector<int> temp;
      for (int b = 0; b < ss; b++)
        temp.push_back(-1);
      dp.push_back(temp);
    }

    int besta = 0;
    int bestb = 0;
    for (int a = 0; a < ss; a++)
      for (int b = a; b < ss; b++)
        if (f(a, b, s, dp) && ((b - a) > (bestb - besta))) {
          besta = a;
          bestb = b;
        }
    string result = "";
    for (int i = besta; i <= bestb; i++)
      result.push_back(s[i]);
    return result;
  }
};

int main() {
  string in;
  cin >> in;
  Solution *s = new Solution();
  cout << s->longestPalindrome(in) << endl;
}
