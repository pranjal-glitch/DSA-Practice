/*Problem Statement

Given a binary tree, count the number of paths that sum to a given value K.

The path does not need to start from root
The path does not need to end at leaf
Path must go downwards (parent → child)

Platform: GfG

  Approach 1: Brute Force

Store path from root to current node
For every node, check all subpaths ending at that node
Time Complexity: O(N²)

  Optimized Approach 2:  (Prefix Sum + HashMap)

We use the idea:
[
\text{Path Sum} = \text{Current Sum} - K
]

Maintain a running sum (currSum)
Use a hashmap to store frequency of prefix sums
If (currSum - K) exists → valid path found

Algo:
 Traverse the tree using DFS
Maintain currSum
Check:
If currSum == K → increment count
If (currSum - K) exists in map → add its frequency
Store current sum in map
Backtrack after recursion */

class Solution {
public:
void solve(Node* root, int k, long long currSum, unordered_map<long long, int> &mp, int &count) {
  if(root == NULL) return;
  currSum += root->data; 
  if(currSum == k) count++;
  if(mp.find(currSum - k) != mp.end()) {
    count += mp[currSum - k]; 
  }
  mp[currSum]++; 
  solve(root->left, k, currSum, mp, count); 
  solve(root->right, k, currSum, mp, count); 
  mp[currSum]--;
}
int countAllPaths(Node *root, int k) 
{ unordered_map<long long, int> mp;
 int count = 0;
 solve(root, k, 0, mp, count);
 return count;
}
};
