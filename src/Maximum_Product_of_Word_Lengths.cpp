
/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Bit Manipulation

*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size() == 0)
            return 0;
        sort(words.begin(), words.end(), cmp);//按照长度降序排序
        vector<int> masks;
        //以下是精髓部分，不要暴力去比较两个字符串是否有公共字符
        //而是做一个字母表，当有某个字母的时候，将那一位置为一
        for(int i = 0; i <= words.size() - 1; i++) {
            int bits = 0;
            if(words[i].compare("") != 0) //这里如果为空，算1 << (words[i][j] - 'a')这一步时会出错
                for(int j = 0; j <= words[i].length() - 1; j++) {
                    bits |= 1 << (words[i][j] - 'a');   //取或，即将这个字符的表添加到总表上
                    
                }
            masks.push_back(bits);
        }
        int maxNum = 0;
        for(int i = 0; i <= words.size() - 1; i++) {
            if(words[i].length() * words[i].length() <= maxNum )
                break;//因为是按照长度排序的，如果这里都小于最大值了，就剪枝
            for(int j = i + 1; j <= words.size() - 1; j++) {
                if((masks[i] & masks[j]) == 0) {
                    maxNum =  words[i].length() * words[j].length() > maxNum ?words[i].length() * words[j].length():maxNum;
                    break;//同理，接下来肯定小于这个值了，不用算了
                }
            }
        }
        return maxNum;
        
    }
    static bool cmp(string w1, string w2) {
        if(w1.length() > w2.length())
            return true;
        else
            return false;
        
    }
};
