/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

 

Example 1:



Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
*/

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
        show();
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
        show();
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
        show();
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
        show();
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