/*Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

Subscribe to see which companies asked this question

Hide Tags Hash Table Sort
Show Similar Problems
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int smap[26] = {0};
        int tmap[26] = {0};
        for(char c : s) {
            smap[c - 'a']++;
        }
        for(char c : t) {
            tmap[c - 'a']++;
        }
        
        for(int i = 0; i <= 25; i++) {
            if(smap[i] !=  tmap[i])
                return false;
        }
        return true;
        
    }
};