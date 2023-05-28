class Solution {
public:
    int f(vector<int>& nums, int n, vector<int>& dp) {
      if(n == 0) return nums[0];
      if(n == 1) return nums[0] > nums[1] ? nums[0] : nums[1];
      if(dp[n] >= 0) return dp[n];

      dp[n] = max(f(nums, n-1, dp), f(nums, n-2, dp) + nums[n]);
      return dp[n];
    }

    int rob(vector<int>& nums) {
      int ns = nums.size();
      vector<int> dp(ns, -1);
      return f(nums, ns-1, dp);
    }
};

/*

dp[n]: "The maximum amount of money you can get robbing up to the house n"

f(0) = nums[0]
f(1) = max(nums[0], nums[1]);
f(2) = max(nums[1], f(0) + nums[2])

f(n) = max(        // f(n) is the maximum of...
  f(n-1),          // robbing up to the house "n-1" or...
  f(n-2) + nums[n] // robbing up to two houses ago "n-2" and adding the money of the current house
)

*/

