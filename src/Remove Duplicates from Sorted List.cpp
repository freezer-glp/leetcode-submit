//Remove Duplicates from Sorted List
/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *h =NULL,*cptr,*nptr,*index;
		if(head == NULL)
			return NULL;
		index = head;
		while(index != NULL){
			nptr = new ListNode(index -> val);
			if(h  == NULL){
				h  = nptr;
				cptr = nptr;
			}else{
				if(cptr -> val != nptr -> val){
					cptr -> next = nptr;
					cptr = nptr;
				}
			}
			index = index -> next;
		}
		return h ;
    }
};