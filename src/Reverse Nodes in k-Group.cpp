/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Subscribe to see which companies asked this question

Hide Tags Linked List
Show Similar Problems
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1)
            return head;
       // cout<<"head:"<<head -> val<<endl;
        int count = k;
        ListNode* ptr = head;
        while(count != 0 && ptr != NULL) {
            ptr = ptr -> next;
            count --;
        }
        if(count != 0)
            return head;
       // if(ptr)
         //   cout<<ptr->val<<endl;
        ListNode* newHead = reverse(head, ptr);
    //    cout<<"newHead:"<<newHead -> val<<endl;
        ListNode* cur = newHead;
        while(cur != NULL && cur -> next != NULL)
            cur = cur -> next;
        ListNode* secondHalf = reverseKGroup(ptr, k);
        cur -> next = secondHalf;
        return newHead;
    }
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* cur = head;
        ListNode* pre = NULL, * next = next;
        while(cur != tail) {
            next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};