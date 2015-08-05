/*Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.*/
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
        void reorderList(ListNode* head) {
    		if(!head || head -> next == NULL)
    			return;
           
    		//find mid
    		ListNode* slow = head;
    		ListNode* fast = head;
    		while(fast -> next != NULL && fast -> next -> next != NULL){
    			slow = slow -> next;
    			fast = fast -> next -> next;
    		}
    		//slow is the mid node
    		ListNode* lhead = slow -> next;
    		slow -> next = NULL;//set mid next as null
    
    		//reverse the second half list
    		ListNode* p1 = lhead;
    		ListNode* p2 = lhead -> next, * p3;
    		while(p2){
    			p3 = p2 -> next;
    			p2 -> next = p1;
    			p1 = p2;
    			p2 = p3;
    		}
    		lhead -> next = NULL;
    
    		//merge two parts
    		ListNode * temp = p1;
    		ListNode * c1 = head;
    		while(temp){
    			ListNode* buffer = temp -> next;
    			temp -> next = c1 -> next;
    			c1 -> next = temp;
    			temp = buffer;
    			c1 = c1 -> next -> next;
    		}
        }
};
/*class Solution { time limit exceeding
public:
    void reorderList(ListNode* head) {
		if(!head || head -> next == NULL)
			return;
        ListNode* cptr = head;
		while(cptr -> next != NULL && cptr -> next -> next != NULL){//not the last node and not the two nodes
			ListNode* lptr = cptr -> next;
			while(lptr -> next ->next != NULL){//find the last - 1 node
				lptr = lptr -> next;
			}
			//change the order
			ListNode* last = lptr -> next;
			lptr -> next = NULL;
			last -> next = cptr -> next;
			cptr -> next = last;
			cptr = cptr -> next -> next;

		}
}*/