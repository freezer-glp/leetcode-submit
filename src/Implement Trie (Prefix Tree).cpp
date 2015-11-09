/*Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

Subscribe to see which companies asked this question

Hide Tags Trie Design
Show Similar Problems
*/
class TrieNode {
public:
    // Initialize your data structure here.
    char val;
    int end;//mark a node wether it is a end of a word ,e.g. first we insert abc,the 'c' node's end is 1,and the 'b' node's end is
    // 0. then we insert ab, this time ,we mard the 'b' node's end as 1
    vector<TrieNode* > subtrees;
    TrieNode() {
        end = 0;
    }
    TrieNode(char c) {
        val = c;
        end = 0;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        doInsert(root, 0, word);
    }
    
    TrieNode* findInSubTree(TrieNode* root, char c) {
        if(root -> subtrees.size() != 0)
            for(int i = 0; i <= root -> subtrees.size() - 1; i++) {
                if(root -> subtrees[i] -> val == c) {
                    return root -> subtrees[i];
                }
            }
        return NULL;
    }
    
    void doInsert(TrieNode* root, int index, string word) {
        if(index > word.length() - 1) //insert has already done
            return ;
        TrieNode* hintSubTree = findInSubTree(root, word[index]);
        if(root -> subtrees.size() == 0 || !hintSubTree) {//first see this char
            TrieNode * curNode = new TrieNode(word[index]);
            if(index == word.length() - 1)//just insert the last char
            	curNode -> end = 1;
            root -> subtrees.push_back(curNode);
            doInsert(curNode, index + 1, word);
        }else {
        	if(index == word.length() - 1)//just insert the last char
            	hintSubTree -> end = 1;
            doInsert(hintSubTree, index + 1, word);
        }
    }
    
    bool doSearch(TrieNode* root, int index, string word) {
        
        if(index > word.length() - 1 )
            if(root -> subtrees.size() == 0)
                return true;
            else
                return false;
        // cout<<index<<" "<<root -> val<<" "<<word[index]<<endl;
        if(root -> val == word[index]) {
            if(root -> subtrees.size() != 0)
            	if(index == word.length() - 1 ) {
            		if(root -> end != 1)
            			return false;
            	}else
	                for(int i = 0; i <= root -> subtrees.size() - 1; i++) {
	                     bool result = doSearch(root -> subtrees[i], index + 1, word);
	                     if(result)//find
	                        return true;
	                     //if not find this time,continue
	                }
            if(index < word.length() - 1)
                return false;
            else
                return true;
        }else
            return false;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * findInRoot = findInSubTree(root, word[0]);
        if(!findInRoot) {//the first char is not found
            return false;
        }else {
            return doSearch(findInRoot, 0, word);   
        }
    }
 
    bool checkStartWith(TrieNode* root, int index, string word) {
         if(index > word.length() - 1)
            return true;
        if(root -> val == word[index]) {
            if(root -> subtrees.size() != 0)
                for(int i = 0; i <= root -> subtrees.size() - 1; i++) {
                 bool result = checkStartWith(root -> subtrees[i], index + 1, word);
                 if(result)//find
                    return true;
                }
            if(index < word.length() - 1)
                return false;
            else
                return true;
        }else
            return false;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
         TrieNode * findInRoot = findInSubTree(root, prefix[0]);
        if(!findInRoot) {//the first char is not found
            return false;
        }else {
            return checkStartWith(findInRoot, 0, prefix);   
        }
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");