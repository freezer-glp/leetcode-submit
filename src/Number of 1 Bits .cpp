/*Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0)
            return 0;
        uint32_t num = n;
        int count = 0;
        while(num != 0){
            int temp = num % 2;
            num = num / 2;
            if (temp == 1)
                count++;
            
        }
        return count;
    }
};