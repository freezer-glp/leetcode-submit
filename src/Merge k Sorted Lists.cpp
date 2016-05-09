/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Subscribe to see which companies asked this question

Hide Tags Divide and Conquer Linked List Heap
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0 )
            return NULL;
        return mergeKLists(lists, 0, lists.size() - 1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int low, int high) {
       
        if(low == high)
            return lists[low];
        int mid = (low + high) >> 1; 
         //cout<<"low:"<<low<<" mid:"<<mid<<" high:"<<high<<endl;
        return mergeList(mergeKLists(lists, low, mid), mergeKLists(lists, mid + 1, high));
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* tmpHead = new ListNode(-1);
        ListNode* tail = tmpHead;
        while(l1 && l2) {
            if(l1 -> val < l2 -> val) {
                tail -> next = l1;
                l1 = l1 -> next;
            }else {
                tail -> next = l2;
                l2 = l2 -> next;
            }
            tail = tail -> next;
        }
        if(!l1)
            tail -> next = l2;
        else
            tail -> next = l1;
        return tmpHead -> next;
    }
    
};