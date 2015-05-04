/*Description:

Count the number of prime numbers less than a non-negative number, n*/
class Solution {
public:
    int countPrimes(int n) {
        int *prime = new int[n+1];//筛选法求素数
        for(int i = 0; i < n; i++)
            if(i % 2 == 0)
                prime[i] = 0;
            else
                prime[i] = 1;
        prime[2] = 1;
        for(int i = 3; i <= sqrt(n); i = i + 2){
            if(prime[i] == 1){
                for(int j = 2 * i; j <= n; j = j + i)
                    prime[j] = 0;
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){//小于n，无等号
            if(prime[i] == 1)
                count++;
        }
        return count;
    }
};