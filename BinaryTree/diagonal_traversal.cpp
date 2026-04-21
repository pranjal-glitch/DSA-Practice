/*
Problem: Diagonal Traversal of Binary Tree
Platform: GFG / Coding Ninjas

Approach:

* Use queue to store left children
* Traverse right nodes in same diagonal
* Push left child into queue for next diagonal

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> diagonalPath(BinaryTreeNode<int>* root) {
vector<int> result;
if (!root) return result;

```
queue<BinaryTreeNode<int>*> q;
q.push(root);

while (!q.empty()) {
    BinaryTreeNode<int>* node = q.front();
    q.pop();

    while (node) {
        result.push_back(node->data);

        if (node->left) {
            q.push(node->left);
        }

        node = node->right;
    }
}

return result;
```

}
