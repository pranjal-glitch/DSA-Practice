void solve(BinaryTreeNode<int>* root, vector<int> &ans, int level){
    //base case
    if(root == NULL){
        return;
    }
    //first node of this level
    if(level == ans.size()){
        ans.push_back(root -> data);
    }
    solve(root -> left, ans, level + 1);
    solve(root -> right, ans, level + 1);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
    
    
}
