/*Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

Hide Tags Linked List
Hide Similar Problems (E) Remove Linked List Elements
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
    void deleteNode(ListNode* node) {
		ListNode* cptr = node;
        while(1){//if we want to delete node1,we just need move nodes after node1 left and make the original node NULL
			cptr -> val =  cptr -> next -> val ;
			if(cptr -> next -> next == NULL)
			    break;
			cptr = cptr -> next;
		}
		cptr -> next = NULL;
    }
};