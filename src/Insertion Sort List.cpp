/*
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
		if (!head || !(head -> next) ){
			return head;
		}
	
		ListNode *newHead = insertionSortList(head -> next);
		if (head -> val <= newHead -> val){
			
			head -> next = newHead;
			return head;
		}else{
			ListNode *cptr = newHead;
			while (cptr -> val < head -> val ){
				if (!(cptr -> next) || cptr -> next -> val >= head -> val){
					break;
				}else{
				    cptr = cptr -> next;
				}
			}
			if(head -> val == 5){
				cout<<cptr-> val <<endl;
			}
			head -> next = cptr -> next;
			cptr -> next = head;
		    return newHead;
		}
    }
};