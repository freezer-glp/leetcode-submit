/*There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
Subscribe to see which companies asked this question

Hide Tags Math Brainteaser
*/
class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0)
            return 0;
        //按照题意直接算，会超时
        // int* bulbs = new int[n + 1];
        // //let 1 means on, 0 means off
        // for(int i = 1; i <= n; i++)
        //     bulbs[i] = 0;
        // for(int i = 1; i <= n; i++) { //n turns in total
        //     for(int j = 1; j <= n; j++) {
        //         if(j % i == 0) {
        //             bulbs[j] = bulbs[j] == 0? 1 : 0;
        //         }
        //     }
        // }
        // int count = 0;
        // for(int i = 1; i <= n; i++)
        //     if(bulbs[i] == 1)
        //         count++;
        
        // return count;
        
        //是时候找找规律了, 还是超时。。。
        // if(n == 1)
        //     return 1;
        // int count = 0;
        // for(int i = 2; i <= n; i++) {
        //     if(n % i == 0)
        //         count++;
        // }
        // if(count % 2 == 0) {
        //     return bulbSwitch(n - 1) + 1;
        // }else
        //     return bulbSwitch(n - 1);
            
        //要不提前算一个整除数的表试试？a[i]里存i这个数在 2 ~ i 之中有多少个因子，当n=9999999时，依旧超时。。。
        // int* a = new int[n + 1];
        // for(int i = 0; i <= n; i++)
        //     a[i] = 1;
        // for(int i = 2; i <= n; i++) {
        //     for(int j = 2; ; j++) {
        //         int tmp = i * j;
        //         if(tmp <= n)
        //             a[tmp]++;
        //         else
        //             break;
        //     }
        // }
        // int count = 0;
        // for(int i = 1; i <= n; i++) {
        //     if(i == 1)
        //         count++;
        //     else {
        //         if(a[i] % 2 == 0)
        //             count++;
        //     }
        // }
        // return count;
        
        //看了魔方大神的解答，给跪了：当一个位置i 在 1 ~ i中有奇数个因子时，这个灯才会亮着，但
        //因子都是成对出现的，所以只有完全平方数，才可能有奇数个因子。sqrt(n)向下取整，其值恰好是1 ~ n中最大的完全平方数的根
        //所以在1 ~ n中恰好友sqrt(n)个完全平方数
        return (int)sqrt(n);
    }
};