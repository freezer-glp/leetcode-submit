/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
      if (!root) return nullptr;
      if (root->left && root->right) {
        root->left->next = root->right;
      }
      // find root->next;
      Node* next = root->next;
      while(next && next->next && !next->left && !next->right) next = next->next;
      if (root->right && next) {
        root->right->next = next->left?next->left: 
            next->right?next->right:nullptr;
      } else if (root->left && !root->right && next) {
        root->left->next = next->left?next->left: 
            next->right?next->right:nullptr;
      }
      // 重点来了！先右后左，因为左边连接需要右边的连接信息
      // 先确保 root.right 下的节点的已完全连接，因 root.left 下的节点的连接
        // 需要 root.left.next 下的节点的信息，若 root.right 下的节点未完全连
        // 接（即先对 root.left 递归），则 root.left.next 下的信息链不完整，将
        // 返回错误的信息。可能出现的错误情况如下图所示。此时，底层最左边节点将无
        // 法获得正确的 next 信息：
        //                  o root
        //                 / \
        //     root.left  o —— o  root.right
        //               /    / \
        //              o —— o   o
        //             /        / \
        //            o        o   o
      connect(root->right);
      connect(root->left);
      return root;
    }
};