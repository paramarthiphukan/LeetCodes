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
     void helper(TreeNode *root,unordered_map<int,int>&m)
    {
        if(!root)
        {
            return;
        }
        helper(root->left,m);
        m[root->val]++;
        helper(root->right,m);
    }
    vector<int> findMode(TreeNode* root) 
    {
        if(!root)
        {
            return {};
        }
        vector<int>v;
        unordered_map<int,int>m;
        helper(root,m);
        priority_queue<pair<int,int>>q;
        int f=INT_MIN;
        for(auto it:m)
        {
            q.push({it.second,it.first});
            f=max(f,it.second);
        }
        while(!q.empty())
        {
            if(q.top().first==f)
            {
                v.push_back(q.top().second);
            }
            else
            {
                break;
            }
            q.pop();
        }
        return v;
    }
};