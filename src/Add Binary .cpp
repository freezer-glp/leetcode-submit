//Add Binary 
/*Given two binary strings, return their sum (also a binary string). 
For example,
a = "11"
b = "1"
Return "100".*/
class Solution {
public:
	string addbit(char a,char b,int &flag){
	
		int a1,b1;
		string ansstring;
		a1 = (a == '#')?0:a -'0';
		b1 = (b == '#')?0:b -'0';
		int ans = a1 + b1 + flag;
		if(ans >= 2){
			ans = ans % 2;
			flag = 1;
		}else
			flag = 0;
		ansstring = ans + '0';
		return ansstring;
	}
    string addBinary(string a, string b) {
        string ans="";
		int flag = 0;
		string temp;
		int i = a.length() - 1, j = b.length() - 1;
		if(i < j){
			temp = a;
			a = b;
			b = temp;
		}
		i = a.length() - 1;
		j = b.length() - 1;
		while(i >= 0 && j >= 0){
			ans = addbit(a[i],b[j],flag) + ans;
			i--;
			j--;
		}
		if(i >= 0){
			while(i >= 0){
				ans = addbit(a[i],'#',flag) + ans;
				i--;
			}
		}
		if(flag == 1)
		    return '1'+ans;
		return ans;

    }
};