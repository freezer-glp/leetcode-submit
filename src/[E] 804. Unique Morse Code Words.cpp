/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.
Return the number of different transformations among all words we have.
Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-morse-code-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    string dict[26] = {".-","-...","-.-.","-..",".","..-.","--.","....",
    "..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...",
    "-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
      unordered_set<std::string> s;
      if (words.size() <= 1) return words.size();
      for (int i = 0; i < words.size(); ++i) {
        std::string tmp = "";
        for (int j = 0; j < words[i].size(); ++j) {
          tmp += dict[words[i][j]-'a'];
        }
        if (s.find(tmp) == s.end()) {
          s.insert(tmp);
        }
      }
      return s.size();
    }
};