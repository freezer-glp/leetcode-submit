/*Implement int sqrt(int x).

Compute and return the square root of x.

Hide Tags Math Binary Search
Show Similar Problems
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) 
            return 0;
        int left = 1, right = x, ans;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mid <= x / mid){
                left = mid + 1;
                ans = mid;
            }else if(mid > x / mid) //mid * mid > x
                right = mid - 1;
           
        }
        return ans;
        
        
    }
};