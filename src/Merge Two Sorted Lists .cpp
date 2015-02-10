//Merge Two Sorted Lists 
/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.*/
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1 == NULL )
			return l2;
		else if(l2 == NULL)
			return l1;
		ListNode *head=NULL,*c1=l1,*c2=l2,*cptr=NULL;
		while(c1 != NULL && c2 != NULL){
			if(c1 -> val < c2 -> val){
				if(head == NULL){	
					head = c1;
					cptr = head;
				}else{
					cptr -> next = c1 ;
					cptr = cptr -> next;
				}
				c1 = c1 -> next;
			}else{
				if(head == NULL){	
					head = c2;
					cptr = head;
				}else{
					cptr -> next = c2 ;
					cptr = cptr -> next;
				}
				c2 = c2 -> next;
			}
		}
		if(c1 == NULL)
			cptr -> next = c2;
		else
			cptr -> next =c1;

		return head;


	}
};