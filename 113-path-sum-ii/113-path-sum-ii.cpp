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
     void f(TreeNode* node,int sum,vector<int>v,vector<vector<int>>&ans)
    {
        if (!node) return;
              v.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            ans.push_back(v);
        f(node -> left, sum - node -> val,v,ans);
        f(node -> right, sum - node -> val,v,ans);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>>ans;
        vector<int >v;
        f(root,targetSum,v,ans);
        return ans;
    }
};