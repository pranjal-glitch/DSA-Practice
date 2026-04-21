/*
Problem: Diameter of Binary Tree
Platform: LeetCode

Approach:

* Use DFS (post-order traversal)
* For each node:
  diameter = max(diameter, left_height + right_height)
* Return height = max(left, right) + 1

Time Complexity: O(n)
Space Complexity: O(h)
*/

class Solution {
public:
int solve(TreeNode<int>* root, int &diameter) {
if (root == NULL) {
return 0;
}

```
    int left = solve(root->left, diameter);
    int right = solve(root->right, diameter);

    diameter = max(diameter, left + right);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode<int>* root) {
    int diameter = 0;
    solve(root, diameter);
    return diameter;
}
```

};
