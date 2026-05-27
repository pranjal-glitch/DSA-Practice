bool solve(BinaryTreeNode<int>* root, long long minVal, long long maxVal){
    if(root == NULL){
        return true;
    }
    if(root -> data <= minVal || root -> data >= maxVal){
        return false;
    }
    return solve(root -> left, minVal, root -> data) && 
    solve(root -> right, root -> data, maxVal);
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    // Write your code here
    return solve(root, LLONG_MIN, LLONG_MAX);
}
