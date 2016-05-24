/*Implement pow(x, n).

Subscribe to see which companies asked this question

Hide Tags Binary Search Math
Show Similar Problems
*/
class Solution {
public:
//     double myPow(double x, int n) {
//     // if(n<0) return 1/x * myPow(1/x, -(n+1));
//     // if(n<0) return myPow(1/x, -n);
//     // if(n==0) return 1;
//     // if(n==2) return x*x;
//     // if(n%2==0) return myPow( myPow(x, n/2), 2);
//     // else return x*myPow( myPow(x, n/2), 2);
// }
    double myPow(double x, int n) {
        // cout<<"n:"<<n<<endl;
        double res;
        int flag =0;
        if(n < 0) {
            flag = 1;
            n = -n;
        }
        if(n == 0)
            res = (double)1;
        else if(n == 1)
            res = x;
        else {
            double tmp;
            if(n % 2 == 0) {
                tmp = myPow(x, n / 2);
                double tmp1 =  tmp * tmp;
                if(fabs(tmp - tmp1 / tmp) < 0.000001)
                    res =  tmp * tmp;
                else
                    return 0;
                res = tmp * tmp;
            }else {
                tmp = myPow(x, (n - 1) / 2);
                double tmp1 = x * tmp * tmp;
                if(fabs(tmp - tmp1 / x / tmp) < 0.000001)
                    res = x * tmp * tmp;
                else
                    return 0;
                
            }
            
        }
        res = flag == 0? res : 1 / res;
            // cout<<"res:"<<res<<endl;
        
        return res;
    }
};