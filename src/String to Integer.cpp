//String to Integer (atoi)
/*Implement atoi to convert a string to an integer. 
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 spoilers alert... click to show requirements for atoi.
 Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.*/
class Solution {
public:
   int atoi(const char *str) {
        int i = 0;
		int len = strlen(str);
		//cout<<"len:"<<len<<endl;
		int sgn;
		while(i < len){
			if(str[i] == ' ')
				i++;
			else
				break;
		}
		if(i >= len)//only whitespace
			return 0;
		if(str[i] == '-'){
			sgn = -1;
			i++;
		}else if(str[i] == '+'){
		    sgn = 1;
		    i++;
		}else if(str[i] >= '0' && str[i] <= '9'){
			sgn = 1;
		}
		else{
			return 0;//not valid
		}
	//	cout<<"i:"<<i<<endl;
	//	cout<<"sgn:"<<sgn<<endl;
		int ans = 0;
		while(i < len){
			
			if(str[i] >= '0' && str[i] <= '9'){
				ans = ans*10 + str[i]-'0';
				i++;
			}
			if(i >= len)
			    break;
			if(!(str[i] >= '0' && str[i] <= '9')){
				break;
			}
			if(sgn == 1 && (ans > INT_MAX / 10||(ans == INT_MAX / 10 && (str[i]-'0')>7))){
				return INT_MAX;
			}
			if(sgn == -1 && (ans > INT_MAX / 10||(ans == INT_MAX / 10 && (str[i]-'0')>8))){
			    return INT_MIN;
			}
			
		}
		return ans*sgn;
    }
};