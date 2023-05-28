/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* play(vector<int>& nums, int low, int high) {
    // !!! CHECK BASE CASES && EDGE CASES
    if(high < low) return NULL;
    
    // find the "biggest"
    int biggest = nums[low];
    int biggest_idx = low;
    for(int i=low+1; i<=high; i++)
      if(biggest < nums[i]) {
        biggest = nums[i];
        biggest_idx = i;
      }
    
    // create a "node" with the biggest - (divid-and-conquer?)
    TreeNode* ans = new TreeNode(biggest,
                                 play(nums, low, biggest_idx-1),
                                 play(nums, biggest_idx+1, high));
    return ans;
  }
  
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return play(nums, 0, nums.size()-1);
  }
};
