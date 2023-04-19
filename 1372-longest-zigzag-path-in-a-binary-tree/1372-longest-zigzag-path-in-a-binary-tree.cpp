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
     int ans = 0; 
     vector<int>postorder(TreeNode* root)
     {
        
        if(root == NULL)
        return {-1, -1};
        
        int left = postorder(root->left)[1] + 1;
        int right = postorder(root->right)[0] + 1;
        
        ans = max({ans, left, right});
        return {left, right};
    }
    
    int longestZigZag(TreeNode* root) 
    {  
        postorder(root);
        return ans;
    }
};