//Palindrome Number
/*Determine whether an integer is a palindrome. Do this without extra space.*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
			return false;
		else{
			int a1=x,a2=0;
			while(a1 != 0){
				a2 = a2 * 10 + a1 %10;
				a1 = a1 /10;
			}
			if(a2 == x)
				return true;
		}
		return false;

    }
};