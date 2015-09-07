/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

Hide Tags Linked List Two Pointers
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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return NULL;
        ListNode* cptr = head, * pcptr = NULL;
        ListNode* newHead = NULL,* newTail = NULL;
        //if a node is less than x,then move this node to the tail of a new list.finally ,merge the two list.
        while(cptr != NULL){
            cout<<cptr -> val<<endl;
            if(cptr -> val < x){
                if(cptr == head){//the  head is less than x
                    head = head -> next;//head move to next
                    if(newTail == NULL){
                        newHead = cptr;
                        newTail = newHead;
                    }else{
                        newTail -> next = cptr;
                        newTail =  newTail -> next;
                    }
                    cptr = cptr -> next;
                }else{//the node that less than x is not the head
                    if(newTail == NULL){
                        newHead = cptr;
                        newTail = newHead;
                    }else{
                        newTail -> next = cptr;
                        newTail =  newTail -> next;
                    }
                    pcptr -> next = cptr -> next;
                    cptr = pcptr -> next;
                }
            }else{//cptr -> val > x
                pcptr = cptr;
                cptr = cptr -> next;
            }
        }
        if(newTail != NULL){
            newTail -> next = head;
            return newHead;
        }else
            return head;
    }
};