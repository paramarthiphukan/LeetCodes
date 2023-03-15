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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            if(!top->left and top->right or !top->right and !q.empty() and q.front()->left) 
				return false;
        }
        return true;
    }
};