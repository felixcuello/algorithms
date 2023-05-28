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
  void play(TreeNode* p, vector<string>& ans, string current) {
    if(p == NULL)
      return;
    
    current += "->" + to_string(p->val);
    
    if(p->left == NULL && p->right == NULL) {
      ans.push_back(current);
      return;
    }
    
    play(p->left, ans, current);
    play(p->right, ans, current);
  }
  
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    
    if(root->left == NULL && root->right == NULL)
      return {to_string(root->val)};
    
    play(root->left, ans, to_string(root->val));
    play(root->right, ans, to_string(root->val));
    
    return ans;
  }
};
