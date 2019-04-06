/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
*/
static int _ = []
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
      if (!s.size() || !d.size()) return "";
      int max = 0, maxi = -1;
      string tmp = "";
      for (int i = 0; i < d.size(); ++i) {
        if (checkExist(s, d[i])) {
          if (d[i].size() >= max) {
            if (tmp.empty() ||
                d[i].size() > max ||
                (d[i].size() == max && d[i] < tmp)) {
              tmp = d[i];
            }
            max = d[i].size();
          }
        }
      }
      return tmp;
    }
  
    bool checkExist(const string& s1, const string& s2) {
      if (!s1.size() || !s2.size()) return false;
      int i = 0;
      int j = 0;
      while (j < s2.size()) {
        bool cur_found = false;
        while (i < s1.size()) {
          if (s1[i] == s2[j]) {
            cur_found = true;
            i++;
            break;
          }
          i++;
        }
        if (!cur_found) return false;
        j++;
      }
      return true;
    }
    
};