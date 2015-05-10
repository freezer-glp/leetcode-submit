/*Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?*/
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
    bool hasCycle(ListNode *head) {
        //if(head == NULL || head -> next == NULL)
        //    return false;
        ListNode *p1=head, *p2=head;
        while(p1 != NULL && p2 != NULL){
            p1 = p1 -> next;
            if(p2 -> next != NULL)
                p2 = p2 -> next -> next;
            else
                return false;
            if(p1 == p2 && p1 != NULL && p2 != NULL)
                return true;
        }
        return false;
        
    }
};