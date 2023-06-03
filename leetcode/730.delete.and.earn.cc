#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
  int f(int n, vector<int>& uniq, map<int, int>& group, map<int, int>& dp) {
    if(n == 0) return group[uniq[0]];
    if(n == 1) {
      if(uniq[0]+1 == uniq[1])
        return max(group[uniq[0]], group[uniq[1]]);
      else
        return group[uniq[0]] + group[uniq[1]];
    }
    if(dp.find(n) != dp.end()) return dp[n];

    if(uniq[n-1] + 1 == uniq[n]) {
      dp[n] = max( f(n-1, uniq, group, dp), f(n-2, uniq, group, dp) + group[uniq[n]]);
    } else {
      dp[n] = f(n-1, uniq, group, dp) + group[uniq[n]];
    }

    return dp[n];
  }

  int deleteAndEarn(vector<int>& nums) {
    vector<int> uniq;
    map<int, int> group;
    int last = -1;

    sort(nums.begin(), nums.end());
    for(auto e : nums) {
      if(e != last) {
        uniq.push_back(e);
        last = e;
      }
      group[e] += e;
    }

    map<int, int> dp;
    int n = uniq.size() - 1;
    return f(n, uniq, group, dp);
  }
};

int main() {
  vector<int> nums;
  int n; cin >> n;
  while(n--) {
    int e; cin >> e;
    nums.push_back(e);
  }

  Solution *s = new Solution();
  cout << s->deleteAndEarn(nums) << endl;
}

