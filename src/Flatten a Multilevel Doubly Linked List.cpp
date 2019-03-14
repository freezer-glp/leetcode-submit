/*
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 

Example:

Input:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Output:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* tail = nullptr;
        flatten(head, &tail);
        return head;
    }
  
  Node* flatten(Node* head, Node** up_tail) {
        Node* cur = head;
        while (cur != nullptr) {
          Node* cur_old_next = cur->next;
          Node* tail = nullptr;
          if (cur->child != nullptr) {
            // flat child list
            Node* child_head = flatten(cur->child, &tail);
            // link cur and child list
            child_head->prev = cur;
            cur->child = nullptr;
            if (cur->next != nullptr) {
              cur->next->prev = tail;
            }
            tail->next = cur->next;
            cur->next = child_head;
          }
          if (cur_old_next == nullptr) {
            if (tail == nullptr) {
              *up_tail = cur;
            } else {
              (*up_tail) = tail;
            }
          }
          cur = cur_old_next;
        }
        return head;
  }
};