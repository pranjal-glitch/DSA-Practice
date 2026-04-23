/*
Problem: Sum Root to Leaf Numbers
Platform: LeetCode

Approach:

* Use DFS traversal
* At each node:
  currentSum = currentSum * 10 + node->val
* If leaf node → return currentSum
* Return sum of left and right subtree results

Time Complexity: O(n)
Space Complexity: O(h)
*/

class Solution {
public:
int dfs(TreeNode* node, int currentSum) {
if (!node) return 0;

```
    currentSum = currentSum * 10 + node->val;

    // Leaf node
    if (!node->left && !node->right)
        return currentSum;

    return dfs(node->left, currentSum) +
           dfs(node->right, currentSum);
}

int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}
```

};
