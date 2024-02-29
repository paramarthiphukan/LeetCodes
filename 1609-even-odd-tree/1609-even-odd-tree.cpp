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
    bool solve(TreeNode* root,int h,unordered_map<int,int>& m)
    {
        if(!root)return 1;
        
        if(m.count(h))
        {
            if(h%2==0)
            {
                if(root->val%2==0 || root->val<=m[h])return 0;
                else m[h]=root->val;
            }
            else
            {
                if(root->val%2!=0 || root->val>=m[h])return 0;
                else m[h]=root->val;
            }
        }
        else
        {
            if((h%2==0 && root->val%2==0) || (h%2!=0 && root->val%2!=0))return 0;
            else m[h]=root->val;
        }
        
        bool a=solve(root->left,h+1,m);
        bool b=solve(root->right,h+1,m);
        
        return a && b;
    }
    bool isEvenOddTree(TreeNode* root) 
    {
        unordered_map<int,int> m;
        return solve(root,0,m);
    }
};