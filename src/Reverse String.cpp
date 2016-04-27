/*Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

Subscribe to see which companies asked this question

Hide Tags Two Pointers String
Show Similar Problems
*/
class Solution {
public:
    string reverseString(string s) {
        if(s.size() == 0)
            return s;
        int i = 0;int j = s.size() - 1;
        while(i < j) {
            char tmp = s[j];
            s[j] = s[i];
            s[i] = tmp;
            i++;
            j--;
        }
        return s;
    }
};