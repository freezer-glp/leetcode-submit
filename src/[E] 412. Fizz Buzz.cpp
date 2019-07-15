/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fizz-buzz
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
      vector<string> res;
      if (n < 1) return res;
      res.resize(n);
      for (int i = 0; i<n; i++) {
        res[i] = "";
        if ((i+1) % 3 == 0) {
          res[i] += "Fizz";
        }
        
        if ((i+1) % 5 == 0) {
          res[i] += "Buzz";
        }
        
        if (res[i] == "") {
          res[i] = std::to_string(i+1);
        }
      }
      return res;
    }
};