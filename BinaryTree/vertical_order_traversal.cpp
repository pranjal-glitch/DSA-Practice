/*
Problem: Binary Tree Vertical Order Traversal
Platform: LeetCode

Approach:

* Use BFS with (node, row, col)
* Store nodes in:
  map<col, map<row, multiset<values>>>
* This ensures:

  * Columns are sorted
  * Rows are sorted
  * Same position values are sorted

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
vector<vector<int>> verticalTraversal(TreeNode* root) {

```
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int,int>>> q;
    
    vector<vector<int>> ans;
    
    if(root == NULL) return ans;
    
    q.push({root, {0, 0}});
    
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        
        TreeNode* node = temp.first;
        int row = temp.second.first;
        int col = temp.second.second;
        
        nodes[col][row].insert(node->val);
        
        if(node->left) {
            q.push({node->left, {row+1, col-1}});
        }
        
        if(node->right) {
            q.push({node->right, {row+1, col+1}});
        }
    }
    
    for(auto &i : nodes) {
        vector<int> colNodes;
        
        for(auto &j : i.second) {
            colNodes.insert(colNodes.end(), j.second.begin(), j.second.end());
        }
        
        ans.push_back(colNodes);
    }
    
    return ans;
}
```

};
