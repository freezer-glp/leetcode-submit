/*Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.*/

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        val = 0;
        next = nullptr;
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= length) { return -1;} 
        
        MyLinkedList* cur = find_xth(index);
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList* new_node = new MyLinkedList();
        new_node->val = val;
        new_node->next = head;
        head = new_node;
        length++;
        if (length == 1) {
            tail = head;
        }
        // show();
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList* new_node = new MyLinkedList();
        new_node->val = val;
        new_node->next = nullptr;
        if (length == 0) {
            tail = new_node;
            head = tail;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        length++;
        // show();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length) return;
        if (index == length) {
            addAtTail(val);
            length--;
        } else {
            MyLinkedList* before = find_xth(index - 1);
            MyLinkedList* new_node = new MyLinkedList();
            new_node->val = val;
            new_node->next = before->next;
            before->next = new_node;
        }
        length++;
        // show();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= length) return;
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }
        MyLinkedList* before = find_xth(index - 1);
        MyLinkedList* del = before->next;
        before->next = del->next;
        delete del;
        if (before->next == nullptr) {
            tail = before;
        }
        length--;
        // show();
    }
    
    MyLinkedList* find_xth(int index) {
        cout<<"find:"<<index<<endl;
        MyLinkedList* cur = head;
        while(index-- > 0) {
            cur = cur->next;
        }
        return cur;
    }
    
    void show() {
        /*
        cout<<"show on length:"<<length<<endl;
        for (MyLinkedList* it = head; it != nullptr; it = it->next) {
            cout<<it->val<<"->";
        }
        cout<<endl;
        */
    }
    int val, length;
    MyLinkedList* next, *head, *tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */