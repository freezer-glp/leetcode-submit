/*Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
Note:
Both the string's length and k will not exceed 104.
Example 1:
Input:
s = "ABAB", k = 2
Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.*/

//  滑动窗口，厉害了
class Solution {
public:
    int characterReplacement(string s, int k) {
      vector<int> a(26, 0);
      int left = 0, right = 0, max = 0, res = 0;
      for (right = 0; right < s.size(); ++right) {
        a[s[right] - 'A'] += 1;
        if (a[s[right] - 'A'] > max) max = a[s[right] - 'A'];
        while(right - left + 1 - max > k) {
          a[s[left++] - 'A']--;
        }
        if ((right - left + 1) > res) 
          res = right - left + 1;
      }
      return res;
    }
};

/*
回溯深搜，会超时
class Solution {
public:
    int characterReplacement(string s, int k) {
      if (s.empty()) return 0;
      int dic[26];
      for (int i =0; i<26;++i) dic[i] =0;
      for(int i =0; i< s.size(); ++i) {
        dic[s[i]-'A'] = 1;
      }
      
      int res = 0;
      bt(s, 0, dic, k, res);
      return res;
    }
  
    void bt(std::string& s, int l, int dic[26], int k, int& res) {
      if (k == 0 || l >= s.size()) { // 当全部都不替换时，会走到第二个条件
        countMax(s, res);
        return;
      }
      char tmp = (s[l]);
      bt(s, l+1, dic, k, res); // 当前位置不进行替换，k不减少
      for (int i =0; i<26 && dic[i] == 1 ; ++i) {
        if (s[l] == ('A' + i)) {
          continue;
        } else {
          s[l] = ('A' + i);
          bt(s, l+1, dic, k-1, res);
        }
      }
      s[l] = tmp; // 恢复现场
    }
    
    void countMax(string& s, int& res) {
      int sum = 0;
      char last = s[0];
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] != last) {
          if (sum > res) res = sum;
          sum = 1;
          last = s[i];
        } else {
          sum++;
        }
      }
      if (sum > res) res = sum;
    }
};
*/