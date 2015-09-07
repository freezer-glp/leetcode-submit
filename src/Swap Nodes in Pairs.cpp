/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Hide Tags Linked List
Hide Similar Problems*/
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* cptr = head;
        if(cptr -> next == NULL){//only one node
            return head;
        }
        ListNode* newHead=NULL, * lastTail=NULL;
        while(cptr != NULL && cptr -> next != NULL){
            ListNode* prev = cptr;
            cptr = cptr -> next;
            cout<<"cv"<<cptr -> val<<" pv"<<prev -> val<<endl;
            prev -> next = cptr -> next;
            cptr -> next = prev;
            if(newHead == NULL){//first round
                newHead = cptr;
            }
            else{//connect to left tail
                lastTail -> next = cptr;
            }
            lastTail = prev;//get new tail from left to right in ordered list
            cptr = prev -> next;//start next round
        }
        return newHead;
    }
};