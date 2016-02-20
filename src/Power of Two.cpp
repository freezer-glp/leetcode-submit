/*Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Math Bit Manipulation
Show Similar Problems
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
            return false;
        while(n > 1 && n % 2 == 0)
           n = n >> 1;
        return n == 1;
    }
};