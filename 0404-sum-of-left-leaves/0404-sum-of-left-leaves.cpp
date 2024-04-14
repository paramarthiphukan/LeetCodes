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
    void helper(TreeNode* root, bool check,int &sum)
    {
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL && check == true)
        {
            sum += root->val;
            return;
        }
        
        if(root->left == NULL && root->right == NULL && check == false)
        {
            return;
        }
        
        helper(root->left,true,sum);
        helper(root->right,false,sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        if(root == NULL || (root->left == NULL && root->right == NULL))
        {
            return 0;
        }
        
        helper(root,true,sum);
        
        return sum;
    }
};