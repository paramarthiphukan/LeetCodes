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
    int  util(TreeNode*root)
    {
        if(root==NULL) return 0;
        
        int left=util(root->left);
        int right=util(root->right);
        int x=root->val;
        if(root->left!=NULL)
        {
            root->val+=root->left->val;
        }
        if(root->right!=NULL)
        {
            root->val+=root->right->val;
        }
        if(root->val/(left+right+1)==x) ans++;
        
        return left+right+1;
        
    }
    int averageOfSubtree(TreeNode* root) 
    {
        util(root);
        return ans;
    }
};