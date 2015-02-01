//Excel Sheet Column Title
/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB */

class Solution {
public:
    string convertToTitle(int n) {
        int a = 0;
		string buf,res="";
	  
		while(1){
			a = n % 26;
			buf = 'A' + (a+25)%26;
			res = buf + res;
			n = n / 26;
			if(a == 0)//means the last char is Z
			    n--;
			if(n == 0)
				break;
		}
		return res;
    }
};