/*
Problem: Lowest Common Ancestor in Binary Tree
Platform: LeetCode / GFG

Approach:

* Use recursion (DFS)
* If current node is NULL → return NULL
* If node matches x or y → return node
* Recur left and right

  * If both sides return non-null → current node is LCA
  * Else return the non-null side

Time Complexity: O(n)
Space Complexity: O(h)
*/

class Solution {
public:
TreeNode<int>* solve(TreeNode<int>* root, int x, int y) {
if(root == NULL){
return NULL;
}

```
    if(root->data == x || root->data == y){
        return root;
    }

    TreeNode<int>* leftAns = solve(root->left, x, y);
    TreeNode<int>* rightAns = solve(root->right, x, y); 
    
    if(leftAns && rightAns){
        return root;
    }
    
    return (leftAns != NULL) ? leftAns : rightAns;
}

int lowestCommonAncestor(TreeNode<int>* root, int x, int y) {
    TreeNode<int>* ans = solve(root, x, y);
    return ans ? ans->data : -1;
}
```

};
