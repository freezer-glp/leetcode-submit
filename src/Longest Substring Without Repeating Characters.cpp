/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question

Hide Tags Hash Table Two Pointers String
Show Similar Problems
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int pre = 1;
        int max = 1;
        if(len == 0)
            return 0;
        for(int i = 1; i < len; i++) {
            int k = i - 1;
            for(; k >= (i - 1) - pre + 1; k--) {
                if(s[i] == s[k]) {
                    pre = (i - 1) - k + 1;
                    break;
                }
            }
            if(k == (i - 1) - pre + 1 - 1) {
                pre += 1;
                max = max > pre ? max : pre;
            }
        }
        return max;
    }
};