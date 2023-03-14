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
      int ans=0;
    void solve(TreeNode * root, int num)
    {
        if(root==NULL)
            return;
        if(root->left ==NULL && root->right==NULL)
        {
            num = num*10 + root->val;
            ans+= num;
            return;
        }
        num = num*10 + root->val;
        solve(root->left,num);
        solve(root->right,num);
    }
    
    int sumNumbers(TreeNode* root) 
    {
        solve(root,0);    
        return ans;
    }
};