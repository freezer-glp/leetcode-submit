/*Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        //双指针，一个指向奇数点，一个指向偶数点，然后向后迭代
        ListNode* odd = head, * co = head;
        if(head -> next == NULL)
            return head;
        ListNode* even = head -> next, * ce = even;
        while(co && ce) {
            if(co -> next)
                co -> next = co -> next -> next;
            else
                co -> next = NULL;
            
            if(ce -> next)
                ce -> next = ce -> next -> next;
            else
                ce -> next = NULL;
            co = co -> next;
            ce = ce -> next;
        }
        ListNode* cnode = odd;
        while(cnode -> next != NULL)
            cnode = cnode -> next;
        cnode -> next = even;
        return odd;
        
        
    }
};