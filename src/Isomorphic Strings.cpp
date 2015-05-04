/*Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
		string res = "";
		map<char,char> m ;
		for(int i=0; i < len; i++){
			char temps = s[i];
			if(m.find(temps) != m.end()){//find the pair
				res += m[temps];
			}else{
				char tempt = t[i];
				for(map<char,char>::iterator it = m.begin();it != m.end(); it++){
					if(it -> second == tempt && it -> first != temps)
						return false;
				}
				m.insert(std::pair<char,char>(temps, tempt));
				res += t[i];
			}
		}
		if(res.compare(t) == 0)
			return true;
		else
			return false;
    }
};