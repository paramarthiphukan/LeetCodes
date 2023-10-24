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
    vector<int> largestValues(TreeNode* root) 
    {
          if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            int mx=INT_MIN;
            while(sz--)
            {
            TreeNode* t=q.front();
                q.pop();
            mx=max(mx,t->val);
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                
            }
            ans.push_back(mx);
        }
        return ans;
        
    }
};
