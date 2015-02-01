//Binary Tree Level Order Traversal 
/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).*/
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	
	struct Node
	{
		struct TreeNode *ptr;
		int level;
	};
	
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<struct Node> q1;
		vector<vector<int> > v1;
		vector<int> *v2 = new vector<int>;
		int level =1;
		struct Node * nptr,*cptr;
		nptr = new Node;
		if(root != NULL){
		    nptr->ptr = root;
		    nptr->level = 1;
		    q1.push(*nptr);
		}
		while(!q1.empty()){
			cptr = &q1.front();
			q1.pop();
			if(cptr ->ptr-> left != NULL){
				nptr = new  Node;
				nptr->ptr =cptr ->ptr-> left;
				nptr->level = cptr -> level + 1;
				q1.push(*nptr);
			}
			if(cptr ->ptr-> right != NULL){
				nptr = new  Node;
				nptr->ptr =cptr ->ptr-> right;
				nptr->level = cptr -> level + 1;
				q1.push(*nptr);
			}
			if(cptr->level == level){
				v2->push_back(cptr->ptr->val);
				
			}else{
				level = cptr->level;
				v1.push_back(*v2);
				v2 = new vector<int>;
				v2->push_back(cptr->ptr->val);
			    
			}
			if(q1.empty())
			    v1.push_back(*v2);
				
		}
		return v1;
        
    }
};