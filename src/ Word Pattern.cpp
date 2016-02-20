/*Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Hash Table
Show Similar Problems
*/
class Solution {
public:
    map<char, string> m;
    bool wordPattern(string pattern, string str) {
        checkWord(pattern, 0, str, 0);
    }
    bool checkWord(string& pattern, int pi, string& str, int si) {
        if(pi == pattern.size() && si == str.size() + 1)
            return true;
        int count = 0;
        for(char c : str) {
            if(c == ' ')
                count++;
        }
        if(count != pattern.size() - 1)
            return false;
        char ptmp = pattern[pi];
        int index = str.find(' ', si);
        if(index == string::npos) {
            //已经是最后一个单词
            index = str.size();
        }
        string subStr = str.substr(si, index - si);
        map<char, string> :: iterator iter;
        iter = m.find(ptmp);
        if(iter == m.end()) {//表中没有出现过patter
            for(iter = m.begin(); iter != m.end(); iter++)
                if(iter -> second == subStr)
                    return false;
            m[ptmp] = subStr;
            return checkWord(pattern, pi + 1, str, index + 1);
        }else
            if(iter -> second == subStr)
                return checkWord(pattern, pi + 1, str, index + 1);
            else
                return false;
    }
};