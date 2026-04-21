/*
Problem: Balanced Binary Tree
Platform: LeetCode

Approach:

* Use DFS (post-order traversal)
* Calculate height while checking balance
* If any subtree is unbalanced → return -1

Time Complexity: O(n)
Space Complexity: O(h)
*/

class Solution {
public:
int checkHeight(TreeNode* root){
if(root == NULL) return 0;

```
    int left = checkHeight(root->left);
    if(left == -1) return -1;

    int right = checkHeight(root->right);
    if(right == -1) return -1;

    if(abs(left - right) > 1) return -1;

    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}
```

};
