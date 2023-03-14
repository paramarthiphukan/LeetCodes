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
    bool solve(TreeNode *a,TreeNode *b)
{
    if(a==NULL && b==NULL)
    {
        return true;
    }
    if(a==NULL && b!=NULL || b==NULL && a!=NULL)
    {
       return false;     
    }
    if(a->val!=b->val)
    {
        return false;
    }
    
    return solve(a->left,b->right) && solve(a->right,b->left);
}
bool isSymmetric(TreeNode* root) {
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
    
    return solve(root->left,root->right);
    
}
  };