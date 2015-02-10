//Remove Nth Node From End of List 
/*Given a linked list, remove the nth node from the end of list and return its head.
Try to do this in one pass.*/
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = 0;
		int step;
		ListNode *cptr = head;
		while(cptr != NULL){
			len++;
			cptr = cptr -> next;
		}
		if(n ==  len){
			return head -> next;
		}else{
			cptr = head;
			step =  len - n - 1;
			while(step != 0){
				cptr = cptr ->  next;
				step--;
			}
			cptr -> next = cptr -> next -> next;
			return head;
		}
    }
};