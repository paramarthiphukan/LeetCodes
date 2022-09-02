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
    vector<double> averageOfLevels(TreeNode* root) 
    {
       vector<double>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*>tq;
            double sum=0;
            int count=0;
            while(!q.empty())
            {
            TreeNode* front = q.front();
            count++;
            sum+=front->val;
            if(front->left)tq.push(front->left);
            if(front->right)tq.push(front->right);
            q.pop();
            }
            double temp = sum/count;
            ans.push_back(temp);
            q=tq;
        }
        return ans;
    }
    
};