/*
Problem: Time to Burn Binary Tree
Platform: Code360 / GFG

Approach:

1. Create parent mapping using BFS
2. Find target (start node)
3. Perform BFS from target:

   * Spread fire to left, right, and parent
   * Count time level-wise

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Step 1: Map parent and find target node
BinaryTreeNode<int>* createParentMapping(
BinaryTreeNode<int>* root,
int start,
map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent
) {
queue<BinaryTreeNode<int>*> q;
q.push(root);

```
BinaryTreeNode<int>* res = NULL;
parent[root] = NULL;

while (!q.empty()) {
    auto node = q.front();
    q.pop();

    if (node->data == start) {
        res = node;
    }

    if (node->left) {
        parent[node->left] = node;
        q.push(node->left);
    }

    if (node->right) {
        parent[node->right] = node;
        q.push(node->right);
    }
}

return res;
```

}

// Step 2: BFS to simulate burning
int burnTree(BinaryTreeNode<int>* startNode,
map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent) {

```
map<BinaryTreeNode<int>*, bool> visited;
queue<BinaryTreeNode<int>*> q;

q.push(startNode);
visited[startNode] = true;

int time = 0;

while (!q.empty()) {
    int size = q.size();
    bool spread = false;

    for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();

        if (node->left && !visited[node->left]) {
            spread = true;
            visited[node->left] = true;
            q.push(node->left);
        }

        if (node->right && !visited[node->right]) {
            spread = true;
            visited[node->right] = true;
            q.push(node->right);
        }

        if (parent[node] && !visited[parent[node]]) {
            spread = true;
            visited[parent[node]] = true;
            q.push(parent[node]);
        }
    }

    if (spread) time++;
}

return time;
```

}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;

```
BinaryTreeNode<int>* startNode =
    createParentMapping(root, start, parent);

return burnTree(startNode, parent);
```

}
