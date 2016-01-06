/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode* p0 = head;
        ListNode* p1,* p2, * p3,* tail;
        while(++count < m) {//找到需要逆序的最左节点的前一个节点
            p0 = p0 -> next;
        }
        if(m == 1) {//如果是从头开始逆序，则不存在“最左节点的前一个节点”，需要特别对待
            p1 = head;
            count--;
        }else
            p1 = p0 -> next;
        tail = p1;//原始需要逆序链的最左节点在逆序后将变成最尾节点
        p2 = p1 -> next;
        
        while(count < n) {
            p3 = p2 -> next;
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
            count++;
        }
        tail -> next = p2;
        if(m == 1)
            return p1;
        else {
            p0 -> next =  p1;
            return head;
        }
        
    }
};