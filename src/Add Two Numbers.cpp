/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Hide Tags Linked List Math
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL,* nptr,* cptr;
        int flag = 0,a,b,sum;
        while(l1 != NULL || l2 != NULL){
            a = 0, b = 0, sum = 0;
            if(l1)
                 a = l1 -> val;
            if(l2)
                 b = l2 -> val;
            
            sum = a + b + flag;
            cout<<a<<"+"<<b<<"+"<<flag<<"="<<sum<<endl;
            flag = sum / 10;//计算新的进位
            sum = sum % 10;
            nptr = new ListNode(sum);
            if(!head){
                head =  nptr;
                cptr = nptr;
            }else{
                cptr -> next = nptr;
                cptr = cptr -> next;
            }
            if(l1)
                l1 = l1 -> next;
            if(l2)
                l2 = l2 -> next;
            
        }
        if(flag != 0){//e.g. 5+5 = 10
            cptr -> next = new ListNode(flag); 
        }
        return head;
    }
};