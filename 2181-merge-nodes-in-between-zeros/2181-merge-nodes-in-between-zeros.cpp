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
class Solution {
public:
      ListNode* mergeNodes(ListNode* head) 
      {
        ListNode *p=NULL, *q=NULL;
        head = head->next;
        int sum = 0;
        while(head != NULL)
        {
            if(head->val == 0) 
            {
                ListNode *temp = new ListNode(sum);
                sum = 0;
                if(p==NULL) p = temp;
                if(q==NULL) q = temp;
                else 
                {
                    q->next = temp;
                    q = temp;
                }
            } else sum += head->val;
            
            head = head->next;
        }
        
        return p;
    }
};