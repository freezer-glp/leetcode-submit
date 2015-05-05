/*Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5*/
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        while(head != NULL && head -> val == val)
			head = head -> next;
		ListNode* cptr = head;
		
		while(cptr != NULL){
		    if(cptr -> next == NULL)
		        return head;
			if( cptr -> next -> val == val){
				cptr -> next = cptr -> next ->next;
			}else{
				cptr = cptr -> next;
			}
		}
		return head;
    }
};