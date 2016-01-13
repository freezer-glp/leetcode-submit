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
        ListNode* pre = NULL;//��¼��ǰ�ڵ��ǰһ���ڵ�
        ListNode* cur = head;
        while(cur != NULL) {
            if(cur -> next != NULL && cur -> val != cur -> next -> val) {//���û���ظ�
                pre = cur;
                cur = cur -> next;
            }else if(cur -> next != NULL && cur -> val == cur -> next -> val){//�����ظ�
                int flag = cur -> val;
                for(; cur != NULL && cur -> val == flag; cur = cur -> next);//�������е��ظ��Ľڵ�
                if(pre == NULL) {//��ʾ��ͷ��ʼ�����ظ���
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