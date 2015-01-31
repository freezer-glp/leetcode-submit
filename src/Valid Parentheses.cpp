//Valid Parentheses 
/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
		for(int i = 0 ;i <= s.size()-1;i++){
			if(s[i]=='(' || s[i]=='[' || s[i]=='{')
				t.push(s[i]);
			else{
				if(t.empty())
					return false;
				char top = t.top();
				if(s[i]==')' && top=='(' || s[i]==']' && top=='[' ||s[i]=='}' && top=='{')
					t.pop();
				else
					return false;
			}
		}
		return t.empty();
    }
};