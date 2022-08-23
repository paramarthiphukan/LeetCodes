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
    int idx=0;
    vector<int>pre;
    vector<int>post; unordered_map<int,int>mp;
    
    TreeNode* generate(int start,int end)
    {
       if(start>end)return NULL;
       TreeNode* newnode=new TreeNode(pre[idx++]);
       if(start==end)return newnode;
       int i=mp[pre[idx]];
       newnode->left=generate(start,i);
       newnode->right=generate(i+1,end-1);
      return newnode;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        if(postorder.size()!=preorder.size())return NULL;
        for(int i=0;i<postorder.size();i++)
        {
            mp[postorder[i]]=i;
        }
        pre=preorder;
        post=postorder;
        return generate(0,postorder.size()-1);
    }
};