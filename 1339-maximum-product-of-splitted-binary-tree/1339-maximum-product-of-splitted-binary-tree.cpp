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
class Solution 
{
public:
    void treeTraverse(TreeNode *root, long long &sum)
    {
        sum+= root->val;
        
        if(root->left)treeTraverse(root->left,sum);
        if(root->right)treeTraverse(root->right,sum);
    }
    
    void treeTraverse(TreeNode *root,  long long &sum,  long long&totalSum,  long long&maxProduct)
    {
        int lv = 0;
        int rv = 0;
        long long prod;
        if(root->left)
        {
            treeTraverse(root->left,sum,totalSum,maxProduct);
            prod = (sum * (totalSum-sum));
            if(maxProduct<prod) maxProduct = prod;
            lv = sum;
            sum = 0;
        }
        
        if(root->right)
        {
            treeTraverse(root->right,sum,totalSum,maxProduct);
            prod = (sum * (totalSum-sum));
            if(maxProduct<prod) maxProduct = prod;
            rv = sum;
            sum = 0;
        }
        
        sum = root->val + lv + rv;
    }
    
    int maxProduct(TreeNode* root) 
    {
        
        int MOD = (int)pow(10,9) + 7;
        long long totalSum = 0;
        treeTraverse(root,totalSum);
        long long maxProduct = LLONG_MIN;
        long long sum  = 0;
        treeTraverse(root, sum, totalSum, maxProduct);
        return (int)(maxProduct%MOD);
    }
};