class Solution {
public:
  void dfs(vector<vector<int>>&graph, vector<vector<int>>& ans, vector<int> cur, int node) {
    cur.push_back(node);
    
    if(node == graph.size()-1) {
      ans.push_back(cur);
      return;
    }
    
    int gns = graph[node].size();
    
    for(int i=0; i<gns; i++) {
      dfs(graph, ans, cur, graph[node][i]);
    }
    
    return;
  }
  
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    
    dfs(graph, ans, {}, 0);
    
    return ans;
  }
};

/*

IDEA: DFS

THe idea is simple, run a DFS algorithm.

1. When you find the "nth" node [graph.size()-1] you add that to the solution
2. Otherwise you just discard the solution, because it's never reached.

*/
