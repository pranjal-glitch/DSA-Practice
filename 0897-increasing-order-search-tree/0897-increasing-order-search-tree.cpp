class Solution {
public:
    TreeNode* head = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        root->left = NULL;

        if (prev == NULL)
            head = root;
        else
            prev->right = root;

        prev = root;

        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return head;
    }
};