//Count and Say
/*The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ... 
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.  
Note: The sequence of integers will be represented as a string.*/
class Solution {
public:
    string countAndSay(int n) {
		if(n == 1)
			return "1";
		else{
			string s = countAndSay(n-1);
			string temp,buf;
			string ans="";
			int count = 0;
			int len = s.length();
			int i = 0;
			temp = s[0];
			while(i < len){
			    buf = s[i];
				if(buf.compare(temp)==0){
					count++;
					if(i == len -1){
						buf = '0'+count; 
						ans = ans + buf +temp;
					}
				}else{
					buf = '0'+count;
					ans = ans + buf +temp;
					temp = s[i];
					count = 0;
					i--;
				}
				i++;

			}
			return ans;
		}
    }
};