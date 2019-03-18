/*A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
      string s = S;
      int n = s.size();
      vector<int> res;
      if (n == 0) return res;
      map<char, int> m;
      for (int i = 0; i < n; ++i) {
        char& c = s[i];
        auto it = m.find(c);
        if (it == m.end()) {
          m[c] = i;
        } else {
          it->second = i;
        }
      }
      
      int low = 0;
      while (low < n) {
        int l = low + 1;
        int small = m[s[low]];
        while (l < small) {
          int l_last = m[s[l]];
          if (l_last > small) {
            small = l_last;
          }
          l++;
        }
        res.push_back(small - low + 1);
        low = small + 1;
      }
      return res;
    }
};