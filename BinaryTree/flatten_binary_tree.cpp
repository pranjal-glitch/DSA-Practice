/*
Problem: Flatten Binary Tree to Linked List
Platform: LeetCode / GFG / Code360

Approach:
- Use Morris Traversal concept
- For each node:
    1. Find rightmost node of left subtree
    2. Connect it with current's right subtree
    3. Move left subtree to right
    4. Set left = NULL

Time Complexity: O(n)
Space Complexity: O(1)
*/

void flattenBinaryTree(TreeNode<int>* root)
{
    TreeNode<int>* curr = root;

    while(curr != NULL){

        if(curr->left != NULL){

            // Find predecessor
            TreeNode<int>* pred = curr->left;

            while(pred->right != NULL){
                pred = pred->right;
            }

            // Connect predecessor to right subtree
            pred->right = curr->right;

            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }

        // Move forward
        curr = curr->right;
    }
}
