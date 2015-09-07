/*Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

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
    void reverseList(ListNode*& newHead,ListNode* head){
        ListNode* cptr = head,* nptr;
        while(cptr != NULL){
            if(newHead == NULL){
                newHead = new ListNode(cptr -> val);
            }else{
                nptr = new ListNode(cptr -> val);
                nptr -> next = newHead;
                newHead =  nptr;
            }
            cptr = cptr -> next;
        }
        
    }
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        ListNode* newHead = NULL;
        reverseList(newHead,head);
        ListNode* c1 = head,* c2 = newHead;
        while(c1 != NULL){
            if(c1 -> val != c2 -> val)
                return false;
            c1 = c1 -> next;
            c2 = c2 -> next;
        }
        return true;
        
    }
};