/*
Problem: Top View of Binary Tree
Platform: Code360 / GFG

Approach:

* Use BFS (level order traversal)
* Maintain horizontal distance (hd)
* Store first node encountered at each hd

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <map>
#include <queue>
#include <vector>
using namespace std;

vector<int> getTopView(TreeNode<int> *root)
{
vector<int> ans;
if (!root) return ans;

```
map<int, int> topNode;  // hd -> node data
queue<pair<TreeNode<int>*, int>> q;

q.push({root, 0});

while (!q.empty())
{
    auto temp = q.front();
    q.pop();

    TreeNode<int>* node = temp.first;
    int hd = temp.second;

    // Store first occurrence only
    if (topNode.find(hd) == topNode.end())
    {
        topNode[hd] = node->data;
    }

    if (node->left)
        q.push({node->left, hd - 1});

    if (node->right)
        q.push({node->right, hd + 1});
}

for (auto &i : topNode)
{
    ans.push_back(i.second);
}

return ans;
```

}

