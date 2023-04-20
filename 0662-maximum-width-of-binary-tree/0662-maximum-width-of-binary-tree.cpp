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
     void find(TreeNode* root,unsigned int level,unsigned int loc,unordered_map<unsigned int,pair<unsigned int,unsigned int>> &m)
     {
        if(m.find(level)==m.end())
            m.insert({level,make_pair(UINT_MAX,0)});
       
            m[level].first=min(loc,m[level].first);
            m[level].second=max(loc,m[level].second);
        
        if(root->right!=NULL)
            find(root->right,level+1,2*loc+1,m);
        if(root->left!=NULL)
            find(root->left,level+1,2*loc,m);
            
    }
    
    int widthOfBinaryTree(TreeNode* root)
    {
        unordered_map<unsigned int,pair<unsigned int,unsigned int>> m;
        
        find(root,1,1,m);
        
        unsigned int ans=0;
        for(auto i: m)
            ans=max(ans,i.second.second-i.second.first+1);
        
        return ans;
    }
};