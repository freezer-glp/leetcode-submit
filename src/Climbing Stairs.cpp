/*You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int a = 1, b = 2;
        for(int i = 3; i <= n; i++) {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
    //递归超时
    // int climbStairs(int n) {
    //     if(n <= 1 )
    //         return 1;
    //     else 
    //         return climbStairs(n - 1) + climbStairs(n - 2);
    // }
};