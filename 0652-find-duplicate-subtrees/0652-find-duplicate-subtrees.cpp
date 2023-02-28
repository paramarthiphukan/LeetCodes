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
     string util(TreeNode *root,unordered_map<string,int> &m, vector<TreeNode*> &ans){
        if(!root)
          return "*";
		  
         string s="";
        string l=util(root->left,m,ans);
        string r=util(root->right,m,ans);
        
        s+="*"+to_string(root->val) + l + r ;
        
        if(m[s]!=-1)         
          m[s]++;
        
        if(m[s]>=2)
        {
            ans.push_back(root);
            m[s]=-1;                        

        }
     
        return s; 
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*> ans;
        unordered_map< string,int> m;
        util(root,m,ans);
       
        return ans;
    }
};