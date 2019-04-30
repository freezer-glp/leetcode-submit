/*
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      if (start.size() != end.size()) return -1;
      if (std::find(bank.begin(), bank.end(), end) == bank.end()) return -1;
      unordered_set<string> dict(bank.begin(), bank.end());
      unordered_set<string> ss{start};
      unordered_set<string> es{end};
      vector<char> gene{'A', 'C', 'G', 'T'};
      int step = 0;
      while (!ss.empty()) {
        step++;
        unordered_set<string> tmp_set;
        for (auto& str: ss) {
          dict.erase(str);
          for (int i = 0; i < str.size(); ++i) {
            string tmp = str;
            for (auto& c : gene) {
              tmp[i] = c;
              if (es.find(tmp) != es.end()) return step;
              if (dict.find(tmp) != dict.end()) {
                tmp_set.insert(tmp);
              }
            }
          }
          //ss.erase(str);
        }
        if (tmp_set.size() < es.size()) {
          ss = tmp_set;
        } else {
          ss = es;
          es = tmp_set;
        }
      }
      return -1;
      
    }
};