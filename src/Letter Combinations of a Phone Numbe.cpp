/*Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
Hide Tags Backtracking String
Show Similar Problems
*/
class Solution {
public:
	string[10] n;
	void init(){
		n[0] = " ";
		n[1] = "";
		n[2] = "abc";
		n[3] = "def";
		n[4] = "ghi";
		n[5] = "jkl";
		n[6] = "mno";
		n[7] = "pqrs";
		n[8] = "tuv";
		n[9] = "wxyz";
	}
    vector<string> letterCombinations(string digits) {
        vector<string> v;
		init();
		v = getComb(digits);
		return v;
	}
	vector<string> getComb(string digits){
		vector<string> v;
		if(digits == null || digits == "")
			return v;
		string temp = digits.substr(1);
		vector<string> vt = getComb(temp);
		string fString = n[digits[0] - '0'];//get the string on keyboard
		for(char i :fstring)
			for(string j : vt){
			string newtemp = i + j;
			v.push_back(newtemp);
		}
		return v;
	}


};