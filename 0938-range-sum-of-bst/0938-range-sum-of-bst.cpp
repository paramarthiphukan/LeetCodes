class Solution {
public:
 void pre(TreeNode* root,int low,int high,int &sum)
    {
        if(root==NULL)
        return;
        if(root->val<=high && root->val>=low)
        sum=sum+root->val;
        pre(root->left,low,high,sum);
        pre(root->right,low,high,sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
         int sum=0;
        pre(root,low,high,sum);
        return sum;
    }
};