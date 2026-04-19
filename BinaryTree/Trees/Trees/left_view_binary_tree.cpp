/*
Problem: Left View of Binary Tree
Platform: GFG / Practice

Approach:

* Use Level Order Traversal (BFS)
* For each level, pick the first node
* Push left child first, then right child

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node* left;
Node* right;

```
Node(int val) {
    data = val;
    left = right = NULL;
}
```

};

vector<int> leftView(Node* root) {
vector<int> result;

```
if (root == NULL) return result;

queue<Node*> q;
q.push(root);

while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
        Node* temp = q.front();
        q.pop();

        // First node of each level
        if (i == 0) {
            result.push_back(temp->data);
        }

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

return result;
```

}
