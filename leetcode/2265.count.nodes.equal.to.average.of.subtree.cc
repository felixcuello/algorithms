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
  // p.first => sum of nodes / p.second => number of nodes
  void dfs(TreeNode* root, int& ans, pair<int,int>& p) {
    if(root->left == NULL && root->right == NULL) {
      p.first += root->val;
      p.second++;
      if((p.first / p.second) == root->val)
        ans++;
      return;
    }
    
    pair<int,int> left = {0,0};
    pair<int,int> right = {0,0};
    
    if(root->left) {
      dfs(root->left, ans, left);
      p.first += left.first;
      p.second += left.second;
    }
    
    if(root->right) {
      dfs(root->right, ans, right);
      p.first += right.first;
      p.second += right.second;
    }
    
    p.first += root->val;
    p.second += 1;
    
    if((p.first / p.second) == root->val)
      ans++;
  }
  
  int averageOfSubtree(TreeNode* root) {
    int ans = 0;
    pair<int,int> p = {0,0};
    
    dfs(root, ans, p);
    
    return ans;
  }
};

/*

Idea: O(n)

Algorithm:

1. Run a DFS from each node / params (TreeNode* node, int& ans, int& sum, int& nodes)
2. cur must return pair<number_of_nodes, sum_of_nodes> for that tree

*/
