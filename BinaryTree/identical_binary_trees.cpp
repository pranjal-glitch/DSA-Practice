/*
Problem: Check if Two Binary Trees are Identical
Platform: GFG / LeetCode

Approach:

* Use recursion
* If both nodes are NULL → return true
* If one is NULL → return false
* Check:

  * current node value
  * left subtree
  * right subtree

Time Complexity: O(n)
Space Complexity: O(h)
*/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {

```
if(root1 == NULL && root2 == NULL){
    return true;
}

if(root1 == NULL || root2 == NULL){
    return false;
}

return (root1->data == root2->data) &&
       identicalTrees(root1->left, root2->left) &&
       identicalTrees(root1->right, root2->right);
```

}
