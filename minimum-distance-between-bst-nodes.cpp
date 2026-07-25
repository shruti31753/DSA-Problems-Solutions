class Solution {
public:
    TreeNode* prev = NULL;
    int minDist(TreeNode* root){
        if(root == NULL){
            return INT_MAX;
        }
        int ans = INT_MAX;
        if(root->left){
            int leftmin = minDist(root->left);
            ans = min(ans, leftmin);
        }
        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        if(root->right){
            int rightmin = minDist(root->right);
            ans = min(ans, rightmin);
        }
        return ans;
    }
public:
    int minDiffInBST(TreeNode* root) {
        return minDist(root);
    }
};
