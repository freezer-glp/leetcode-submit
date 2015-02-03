//Reverse Integer
/*Reverse digits of an integer. 
Example1: x = 123, return 321
Example2: x = -123, return -321*/
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)//if x == INT_MIN we can not compute temp = -x 
            return 0;
        int flag = 1;//means positive
		int temp = x;
		if(x < 0){
			temp = -x;
			flag = -1;
		}
		int ans = 0;
		while(temp != 0){
		    if(ans > INT_MAX /10)//next step we will compute ans * 10 ,so we check the value here
		        return 0;
		    ans = ans *10 + temp%10;
		    temp = temp /10;
		}
		return ans*flag;
    }
};