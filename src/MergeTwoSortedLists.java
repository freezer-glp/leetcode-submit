package MergeTwoSortedLists;

public class MergeTwoSortedLists
{

    // Definition for singly-linked list.

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //两个链的光标
        ListNode cl1 = l1;
        ListNode cl2 = l2;
        ListNode newRoot = null;
        while(l1.next != null || l2.next != null){
            if(l1.val <= l2.val){
                
            }else if(l1.val > l2.val){
                
            }
        }
        
        
        return newRoot;

    }
    
    public 
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub

    }

}

class ListNode
{
    int      val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}