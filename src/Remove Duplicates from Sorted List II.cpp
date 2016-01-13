/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Subscribe to see which companies asked this question

Hide Tags Linked List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* pre = NULL;//记录当前节点的前一个节点
        ListNode* cur = head;
        while(cur != NULL) {
            if(cur -> next != NULL && cur -> val != cur -> next -> val) {//如果没有重复
                pre = cur;
                cur = cur -> next;
            }else if(cur -> next != NULL && cur -> val == cur -> next -> val){//发现重复
                int flag = cur -> val;
                for(; cur != NULL && cur -> val == flag; cur = cur -> next);//跳过所有的重复的节点
                if(pre == NULL) {//表示从头开始就是重复的
                    head = cur;
                }else {
                    pre -> next = cur;
                }
            }else//cur -> next == NULL
                cur = cur -> next;
        }
        cur = head;
        return head;
        
    }
};