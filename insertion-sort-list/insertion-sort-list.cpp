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
    void insert(ListNode *dummy, ListNode *node)
    {
        auto pre = dummy, p = dummy->next;
        while (p != nullptr && p->val <= node->val) pre = p, p = p->next;
        pre->next = node;
        node->next = p;
        
    }
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode dummy(-1, head);
        auto p = head;
        while (p)
        {
            auto next = p->next;
            p->next = nullptr;
            insert(&dummy, p);
            p = next;
        }
        return dummy.next;
    }
};