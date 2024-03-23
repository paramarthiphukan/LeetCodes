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
    ListNode* reverseLL(ListNode* head) 
    {
	ListNode* prev = NULL;
    ListNode* curr = head;
	while (curr) 
    {
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

void reorderList(ListNode* head) 
{
	if (!head || !head->next || !head->next->next) return;
	ListNode *s = head;
	ListNode *f = head;
	while (f->next && f->next->next) 
    {
		f = f->next->next;
		s = s->next;
    }

	ListNode *head2 = s->next;
	s->next = NULL;
	head2 = reverseLL(head2);
	ListNode *dummy = head;
	while (head2 && dummy)
    {
		ListNode *temp = head2->next;
		head2->next = dummy->next;
		dummy->next = head2;
		dummy = dummy->next->next;
		head2 = temp;
	}
}
   };
