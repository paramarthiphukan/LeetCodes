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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> lvl;
        queue<TreeNode*> q;
        bool LtoR=true;// 
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();   q.pop();

                lvl.push_back(node->val);
               if(node->left)  q.push(node->left);
               if(node->right) q.push(node->right);
            }
            if(!LtoR) reverse(lvl.begin(),lvl.end());
            res.push_back(lvl);
            lvl.clear();
            LtoR=!LtoR;
        }
        return res;
    }
};