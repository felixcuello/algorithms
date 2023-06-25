#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void f(int n, vector<int>& uniq, map<int,int>& group, map<int,int>& dp) {
    if(n == 0) dp[0] = group[uniq[0]]; // base case 1: just one element
    if(n == 1) dp[1] = max(group[uniq[0]], group[uniq[1]]); // base case 2: just two elements
    if(dp.find(n) != dp.end()) return; // already calculated, no need to continue

    f(n-1, uniq, group, dp);
    if(uniq[n-1]+1 == uniq[n]) {
      cout << "consecutivos" << endl;
      f(n-2, uniq, group, dp);
      dp[n] = max(dp[n-1], dp[n-2] + group[uniq[n]]);
    } else {
      dp[n] = dp[n-1] + group[uniq[n]];
    }

    return;
  }

  int deleteAndEarn(vector<int> &nums) {
    vector<int> uniq;
    map<int,int> group;

    sort(nums.begin(), nums.end());

    int last = -1;
    for(int i=0; i<nums.size(); i++) {
      int e = nums[i];
      if(last != e) {
        uniq.push_back(e);
        last = e;
      }

      group[e] += e;
    }

    map<int,int> dp;
    int n = uniq.size() - 1;
    f(n, uniq, group, dp);

    //for(vector<int>::iterator i=nums.begin(); i!=nums.end(); i++) cout << "nums>" << *i << endl;
    //for(vector<int>::iterator i=uniq.begin(); i!=uniq.end(); i++) cout << "uniq>" << *i << endl;
    //for(map<int,int>::iterator i=group.begin(); i!=group.end(); i++) cout << "group>" << i->first << "->" << i->second << endl;
    for(map<int,int>::iterator i=dp.begin(); i!=dp.end(); i++) cout << "dp>" << i->first << "->" << i->second << endl;
    //cout << "n=" << n << endl;

    return dp[n];
  }
};

int main() {
  int n;
  vector<int> nums;
  cin >> n;
  int last = -1;
  for(int i=0; i<n; i++) {
    int e;
    cin >> e;
    nums.push_back(e);
  }

  Solution* s = new Solution();
  cout << s->deleteAndEarn(nums) << endl;

  return 0;
}
