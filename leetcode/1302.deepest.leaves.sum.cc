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
  int calc_height(TreeNode* root) {
    if(root == NULL) return 0;
    return 1 + max(calc_height(root->left), calc_height(root->right));
  }
  
  int sum_leaves(TreeNode* cur, int h, int ch) {
    if(cur == NULL)
      return 0;
    
    if(cur->left == NULL && cur->right == NULL) {
      if(h == ch)
        return cur->val;
      else
        return 0;
    }
    
    return sum_leaves(cur->left, h, ch+1) + sum_leaves(cur->right, h, ch+1);
  }
  
  int deepestLeavesSum(TreeNode* root) {
    int h = calc_height(root);
    
    return sum_leaves(root, h, 1);
  }
};

/*

IDEA: DFS O(2n)

The idea is that you don't know what are the deepest leaves until you calculate the height
of the binary tree. (I GUESS) the deepest leaves are undistinguishable from the inner leaves.

So the algorithm would be like this:

1. DFS to calculate the height
2. DFS to find leaves:
     if height == tree_height
        ans += node->val
3. profit =)

*/
