/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* slow = head, *fast = head;
        
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
            
        }
        
        if(fast == nullptr || fast->next == nullptr)
            return nullptr;
        
        if(slow == fast)
        {
            slow = head;
            
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            
            return slow;
            
        }
        
        return nullptr;
        
        
        
    }
};