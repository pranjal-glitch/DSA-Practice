/*
Problem: Binary Tree ZigZag Level Order Traversal
Platform: Leetcode

Approach: Use Level Order Traversal (BFS) with Queue
Maintain a flag(leftTo Right)
For each Level: 
If lefToRight -> insert normally
Else -> Insert in reverse index.

Time complexity: O(n)
  Space Complexity: O(n)
  */
class solution{
public:
vector<vector>zigzagLevelOrder(TreeNode* root){
  Vector<vector> result;

if(root == NULL){
return result;
}
queue<TreeNode*> q;
q.push(root);

bool lefToright = true;

while(!q.empty()){
int size = q.size();
vector<int> level(size);

for (int i = 0; i < size; i++){
TreeNode* node = q.front();
q.pop();

int index = leftToright ? i  :(size - i - 1);
level[index] = node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        result.push_back(level);
        leftToRight = !leftToRight;
    }

    return result;
}

};
