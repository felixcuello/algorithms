class Solution {
public:
  void play(vector<int>& nums, vector<vector<int>>& ans, vector<int> curr, int used) {
    int ns = nums.size();
    
    if(ns == curr.size()) {
      ans.push_back(curr);
      return;
    }
    
    for(int i=0; i<ns; i++) {
      if(used & (1 << i)) continue;
      
      curr.push_back(nums[i]);
      play(nums, ans, curr, used | (1 << i));
      curr.pop_back();
    }
  }
  
  vector<vector<int>> permute(vector<int>& nums) {
    int ns = nums.size();
    vector<vector<int>> ans = {};
    
    play(nums, ans, {}, 0);
    
    return ans;
  }
};


/*

Idea:

To generate all the permutations we need to do some backtracking.

Start from the 1st element, then the 2nd, then the 3rd, and go back it is some sort of generationg several trees.


used is a bitset which indicates if a given number has been used (00011) means that elements 0 and 1 were used
       
*/
