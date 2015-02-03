//Plus One
/*Given a non-negative number represented as an array of digits, plus one to the number. 
The digits are stored such that the most significant digit is at the head of the list.*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		vector<int> v(digits);
		int len = v.size();
		int i = len -1;
		int temp;
		int up = 1;
		while(up != 0){
			temp = v[i] + up;
			v[i] = temp % 10;
			if(temp >= 10){  
				if(i == 0){
					v.insert(v.begin(),1);
					up = 0;
				}else
					up = 1;
			}else{ 
				up = 0;
			}
			i--;
			 
		}
		return v;
    }

};