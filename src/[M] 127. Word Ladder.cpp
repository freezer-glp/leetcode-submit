/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> dict(wordList.begin(), wordList.end());
      if (!beginWord.size() || !endWord.size()) return 0;
      if (dict.find(endWord) == dict.end()) return 0;
      unordered_set<string> begin_set{beginWord};
      unordered_set<string> end_set{endWord};
      int step = 1;
      while(!begin_set.empty()) {
        step++;
        for (auto& str : begin_set) {
          dict.erase(str);
        }
        unordered_set<string> tmp_set;
        for (auto& str: begin_set) {
          for (int i = 0; i < str.size(); ++i) {
            string tmp_str = str;
            for (char c = 'a'; c <= 'z'; ++c) {
              tmp_str[i] = c;
              if (end_set.find(tmp_str) != end_set.end()) return step;
              if (dict.find(tmp_str) != dict.end()) {
                tmp_set.insert(tmp_str);
                continue;
              }
            }
          }
        }
        if (tmp_set.size() < end_set.size()) {
          begin_set = tmp_set;
        } else {
          begin_set = end_set;
          end_set = tmp_set;
        }
      }
      return 0;
    }
};