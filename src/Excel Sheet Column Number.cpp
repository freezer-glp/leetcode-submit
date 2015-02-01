//Excel Sheet Column Number 
/*Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 */
class Solution {
public:
    int titleToNumber(string s) {
        int flag = 1;
		int size;
		int sum = 0;
		string end;
		while(1){
			size = s.size();
			end = s[size-1];
			s.erase(size-1,1);//remove the last char
			sum += ((*end.c_str() - 'A')+1) * pow(26,flag-1);
			flag++;
			if(s.size() == 0)
				break;
		}
		return sum;
    }
};