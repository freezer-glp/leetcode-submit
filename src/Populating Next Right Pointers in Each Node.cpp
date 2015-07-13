/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<TreeLinkNode *> q;
		q.push(root);
		int level = 0;
		int nodeNum = 0;
		while(!q.empty()){
			int count = 1;
			nodeNum = pow(2,level);
			TreeLinkNode *tmp = q.front();
			q.pop();
			if(tmp -> left != NULL)
				q.push(tmp -> left);
			if(tmp -> right != NULL)
				q.push(tmp -> right);
			
			while(count < nodeNum){
				TreeLinkNode *tmp1 = q.front();
				q.pop();

				tmp -> next = tmp1;
				tmp = tmp1;
				if(tmp -> left != NULL)
					q.push(tmp -> left);
				if(tmp -> right != NULL)
					q.push(tmp -> right);
				count++;
			}
			tmp -> next = NULL;
			level++;
		}
    }
};