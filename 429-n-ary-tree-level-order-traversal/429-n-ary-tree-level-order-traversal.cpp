/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        if(root == NULL)    return {};
        queue<Node*> q;
        q.push(root);
        vector<int> res;
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            int s = q.size();
            while(s!=0)
            {
                Node* temp = q.front();
                q.pop();
                s--;
                res.push_back(temp->val);
                for(int i=0;i<temp->children.size();i++)
                {
                        q.push(temp->children[i]);
                }
                
            }
            ans.push_back(res);
            res.clear();
        }
        return ans;
    }
};