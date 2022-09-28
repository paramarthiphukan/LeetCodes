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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *dummy = new ListNode(-1,head);
       ListNode *fast=dummy, *slow = dummy;
        
        while(n){
            fast=fast->next;
            n--;
        }
        if(fast->next == NULL){// n equals to size of linked list
            ListNode *temp=head;
            head=head->next;
            delete temp;
        }
        else{
            while(fast->next != NULL){
                fast=fast->next;
                slow=slow->next;
            } 
            ListNode *temp = slow->next;
            slow->next=temp->next;
            delete temp;
        }
        return head;
    }
    
};