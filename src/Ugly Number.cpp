/*Write a program to check whether a given number is an ugly number. 
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7. 
Note that 1 is typically treated as an ugly number. 
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases. 
Hide Tags Math
Show Similar Problems
*/
class Solution {
public:
    bool isUgly(int num) {
       for (int i=2; i<=5 && num; i++){
            if(i == 4)
                continue;
       
            while (num % i == 0)
                num /= i; 
           
       }
        return num == 1;
       
    }
	
 
};