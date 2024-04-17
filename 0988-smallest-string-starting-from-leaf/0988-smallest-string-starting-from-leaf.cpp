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
    vector<string> a;
    void util(TreeNode* root, string s)
    {
        if(root==NULL)
            return;
        s+=(char)(root->val+97);
        if(root->left==NULL && root->right==NULL)
        {
            reverse(s.begin(),s.end());
            a.push_back(s);
            return;
        }
        util(root->left,s);
        util(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) 
    {
        string s="";
        util(root,s);
        sort(a.begin(),a.end());
        if(a.empty())
            return "";
        return a[0];
    }
};