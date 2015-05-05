/*Reverse a singly linked list.*/
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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        if(head -> next == NULL)
            return head;
        ListNode* h1 = reverseList(head -> next);
        ListNode* cptr = h1;
        while(cptr -> next != NULL)
            cptr = cptr -> next;
        cptr -> next = head;
        head -> next = NULL;
        return h1;
    }
};