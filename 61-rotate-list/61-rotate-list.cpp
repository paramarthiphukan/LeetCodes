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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        ListNode* cur=head;
    int cnt=1;
    if(head==NULL || head->next==NULL)return head;
    while(cur->next!=NULL)
    {
        cnt++;
        cur=cur->next;
    }
    ListNode* last=cur;
    k=k%cnt;
    cnt-=k;
    
    cur=head;
    while(--cnt)
    {
        cur=cur->next;
    }
    last->next=head;
    head=cur->next;
    cur->next=NULL;
    return head;
  }
};