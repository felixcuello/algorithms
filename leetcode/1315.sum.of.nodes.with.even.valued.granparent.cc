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
  void dfs(TreeNode* node, int& ans) {
    if(node == NULL) return;
    
    if(node->val % 2 == 0) {
      if(node->left != NULL) {
        if(node->left->left != NULL) ans += node->left->left->val;
        if(node->left->right != NULL) ans += node->left->right->val;
      }
      if(node->right != NULL) {
        if(node->right->left != NULL) ans += node->right->left->val;
        if(node->right->right != NULL) ans += node->right->right->val;
      }
    }
    
    dfs(node->left, ans);
    dfs(node->right, ans);
  }
  
  int sumEvenGrandparent(TreeNode* root) {
    int ans = 0;
    
    dfs(root, ans);
    
    return ans;
  }
};
