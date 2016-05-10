/*Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Subscribe to see which companies asked this question

Hide Tags Two Pointers String
Show Similar Problems
*/
class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        if(len == 0)
            return s;
        int i = 0, j = len - 1;
        while(i < j) {
            while(i < j && (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
                s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U'))
                i++;
            if(i >= j)
                break;
            
            while(i < j && (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' &&
            s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U'))
                j--;
            if(i >= j)
                break;
           // cout<<i<<" "<<j<<endl;
            char tmp = s[j];
            s[j] = s[i];
            s[i] = tmp;
            i++;
            j--;
        }
        return s;
        
    }
};