class Solution {
private:
    int ans =0;
    void f(TreeNode* root, int ct){
        if(!root) return;
        if(!root->left && !root->right){
            ct ^= 1 << (root->val - 1);
            if((ct & (ct - 1)) == 0) ans++;
            return;
        }
        ct ^= 1 << (root -> val - 1);
        f(root -> left, ct);
        f(root->right, ct);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ct = 0;
        f(root, ct);
        return ans;
    }
};