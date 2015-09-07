/*Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Hide Tags Linked List Two Pointers
Show Similar Problems
*/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        
        int len = 0;//the length of the list
        ListNode* cptr = head, * tail;
        while(cptr){
            len++;
            tail = cptr;
            cptr = cptr -> next;
        }
        if(k == 0 || k % len == 0)
            return head;
        int move = len - (k % len);//the num to move LEFT!
        cout<<"lm="<<move<<endl;
        cptr = head;
        move = move - 1;//find the last node that needs to move 
        while(move-- != 0)
            cptr = cptr -> next;
            
        ListNode* newHead = cptr -> next;
        cptr -> next = NULL;
        tail -> next = head;
        return newHead;
    }
};