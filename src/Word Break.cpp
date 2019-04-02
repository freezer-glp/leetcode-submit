/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      int len = s.size();
      vector<string>& w = wordDict;
      if (len == 0 || w.empty()) {
        return false;
      }
      
      int dp[len + 1] = {0};
      dp[0] = 1;
      for (int i = 1; i <= len; ++i) {
        for (int j = 0; j < i; ++j) {
          if ((dp[j] == 1) && 
              (find(w.begin(), w.end(), s.substr(j, i - j)) != w.end())) {
            cout<<j<<" "<<i<<" "<<s.substr(j, i - j)<<" is true"<<endl;
            dp[i] = 1;
            break;
          }
        }
      }
      // for (int i = 0; i < len + 1; ++i) 
        // cout <<i<<" "<<dp[i]<<endl;
      return dp[len];
    }
};