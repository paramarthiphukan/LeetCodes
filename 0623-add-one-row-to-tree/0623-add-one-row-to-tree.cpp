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
     TreeNode* newTree(TreeNode *root, int val, int depth) 
     {
        if(root == NULL) return root;
        if(depth == 1) 
        {
            auto left = root->left;
            auto right = root->right;
            root->left = new TreeNode(val, left, nullptr);
            root->right = new TreeNode(val, nullptr, right);
            return root;
        }
        root->left = newTree(root->left, val, depth-1);
        root->right = newTree(root->right, val, depth-1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if(depth == 1)
            return new TreeNode(val, root, NULL);
        return newTree(root, val, depth-1);
    }
};