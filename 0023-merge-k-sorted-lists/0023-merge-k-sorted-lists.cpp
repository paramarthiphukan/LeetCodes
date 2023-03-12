/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<int> nums;
        for(auto it: lists)
        {
            while(it != NULL)
            {
                nums.push_back(it->val);
                it = it->next;
            }
        }
        
        sort(nums.begin(), nums.end());
        
       int n = nums.size();
       ListNode* ans = new ListNode(NULL);
       ListNode* cur = ans;
       
       for(int i=0; i<nums.size(); i++)
       {
           cur->next = new ListNode(nums[i]);
           cur = cur->next;
       }
        
        return ans->next;
    }
};