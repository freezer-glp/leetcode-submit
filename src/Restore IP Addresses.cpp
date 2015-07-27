/*Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Hide Tags Backtracking String
*/
class Solution {
public:
	void getIPs(vector<string>& v,string s){
		if(s == "")
			return;
		int count = 0;
		int lastdot = -1;
		for(int i = s.size(); i >= 0; i--){
			if(s[i] == '.'){
				if(lastdot == -1)
					lastdot = i;
				count++;//total num of '.'
			}
		}
		if(count == 3){//alread has 3 dots
			int l = 0;
			if(lastdot == s.size()-1) //xxx.xxx.xxx. this shape is wrong
				return;
			if(s[lastdot + 1] == '0' && lastdot + 1 != s.size() - 1)//xxx.xxx.xxx.011 should be xxx.xxx.xxx.11
			    return;
			for(int i = lastdot + 1; i <= s.size() - 1; i++){
				l *= 10;
				l += s[i] - '0';
			}
			if( l >= 0 && l <= 255)
				v.push_back(s);
		}
		else{//compute next dot
		    int flag = 0;
			int tempnum = 0;
			int temppos = lastdot + 1;
			if(temppos > s.size() - 1) // xxx.xxx.  less than 3 dots but alread put a dot at the last ,wrong
					return;
			tempnum *= 10;
			tempnum += s[temppos] - '0';
			while(tempnum <= 255 ){
				string newString = s;
				newString.insert(temppos + 1,".");
				getIPs(v,newString);
				// xxx.0xxxx   we only compute xxx.0.xxx(this was computed in the last line of code) .we dont compute xxx.0x.xxx 
        		if(s[temppos] == '0' && temppos == lastdot + 1) 
        		    return;
        		    
				temppos++;
				if(temppos > s.size() - 1)
					break;
				tempnum *= 10;
				tempnum += s[temppos] - '0';

			}
		}
		
	}
    vector<string> restoreIpAddresses(string s) {
		vector<string> v;
		getIPs( v, s);
		return v;
    }
};