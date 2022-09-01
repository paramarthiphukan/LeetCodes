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
     int cnt = 0;
    int function(TreeNode* root,int max_till_now) 
    {
        if(root == NULL) return 0;
        max_till_now = max(max_till_now,root->val);
        if(root->val>=max_till_now) cnt+=1;
        function(root->left,max_till_now);
        function(root->right,max_till_now);
        return cnt;
    }
    int goodNodes(TreeNode* root) 
    {
       return function(root,INT_MIN);
    }
};