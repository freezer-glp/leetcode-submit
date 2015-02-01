//Intersection of Two Linked Lists
/*Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.*/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *c1=headA,*c2=headB,*temp=NULL;
		int la=0,lb=0;
		while(c1 != NULL){
			la++;
			c1 = c1 -> next;
		}
		while(c2 != NULL){
			lb++;
			c2 = c2 -> next;
		}
		c1=headA;
		c2=headB;
		if(la < lb){
			temp = c1;
			c1 = c2;
			c2 = temp;
		}
		int dis = (la > lb)?la-lb:lb-la;
		while(dis-- != 0){
			c1 = c1 -> next;
		}
		while(c1 != c2){
			c1 = c1 -> next;
			c2 = c2 -> next;
		}
		return c1;
    }
};