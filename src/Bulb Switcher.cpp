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
        //��������ֱ���㣬�ᳬʱ
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
        
        //��ʱ�����ҹ�����, ���ǳ�ʱ������
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
            
        //Ҫ����ǰ��һ���������ı����ԣ�a[i]���i������� 2 ~ i ֮���ж��ٸ����ӣ���n=9999999ʱ�����ɳ�ʱ������
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
        
        //����ħ������Ľ�𣬸����ˣ���һ��λ��i �� 1 ~ i��������������ʱ������ƲŻ����ţ���
        //���Ӷ��ǳɶԳ��ֵģ�����ֻ����ȫƽ�������ſ��������������ӡ�sqrt(n)����ȡ������ֵǡ����1 ~ n��������ȫƽ�����ĸ�
        //������1 ~ n��ǡ����sqrt(n)����ȫƽ����
        return (int)sqrt(n);
    }
};