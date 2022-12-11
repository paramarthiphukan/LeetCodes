/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 int util(TreeNode* root, int &ans)
 {
        if(!root)
        {
            return 0;
        }
        int lMax = max(util(root->left, ans), 0);
        int rMax = max(util(root->right, ans), 0);
        ans = max(ans, lMax + rMax + root->val);
        return max(root->val + lMax, root->val + rMax);
    }
    int maxPathSum(TreeNode* root)
    {
        int ans = INT_MIN;
        util(root, ans);
        return ans;
    }
};