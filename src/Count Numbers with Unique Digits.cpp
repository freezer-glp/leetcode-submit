/*Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Hint:

A direct way is to use the backtracking approach.
Backtracking should contains three states which are (the current number, number of steps to get that number and a bitmask which represent which number is marked as visited so far in the current number). Start with state (0,0,0) and count all valid number till we reach number of steps equals to 10n.
This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
Let f(k) = count of numbers with unique digits with length equals k.
f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming Backtracking Math
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 0;
        int map[10] = {0};
        if(n < 0)
            return 0;
        backTrace(n - 1, map, res, true);
        return res;
    }
    void backTrace(int n, int map[], int& resCount, bool startZero) {//如果为true, 则本位可以取0并且不用把bitmap中0置1,因为开头的连续0不算重复
        if(n < 0 ) {
            resCount++;
            return;
        }
        int stepValue = pow(10, n - 1); // 当前递归层数字在整体数字中的阶码
        vector<int> tmpRes;
        for(int i = 0; i <= 9; i++) {
            
            if(map[i] == 0) {
                if(i == 0) {
                    if(!startZero) // 当前的0已经不是开头的0了
                        map[i] = 1;
                }else {
                    if(startZero)
                        startZero = false;
                    map[i] = 1;
                }
                backTrace(n - 1, map, resCount, startZero);
                map[i] = 0;
            }
        }
    }
};