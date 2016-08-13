/*Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Bit Manipulation
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0)
            return 0;
        int count = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
        // 这种不断置0的方法还是超时
        // int res = 0;
        // //cout<<pow(2,32)-1<<endl;
        // int flag[32];
        // int nLen = 0;
        // int tmp = n;
        // while(tmp) {
        //     tmp >>= 1;
        //     nLen++;
        // }
        // // cout<<nLen<<endl;
        // for(int i = 0; i < 32; i++)
        //   flag[i] = 1;
        // for(int i = 0; i < nLen; i++) {
        //     // cout<<"i_>"<<i<<endl;
        //     if(flag[i] == 0)
        //         continue;
        //     int needle = (0x1 << i); 
        //     // cout<<"needle:"<<needle<<endl;
        //     for(int j = m; j <= n; j++) {
        //         // cout<<"i:"<<i<<" j:"<<j<<endl;
        //         if((j & needle) == 0) {
        //             flag[i] = 0;
        //             break;
        //         }
        //     }
        // }
        
        // for(int i = 0; i < nLen; i++) {
        //     if(flag[i] == 1) {
        //         res += (0x1 << i);
        //     }
        // }
      
        // return res;
    }
};