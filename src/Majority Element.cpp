/*Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
		map <int ,int > hm;
		map <int, int> :: iterator it;
		
		for(int i = 0;i <= num.size()-1;i++){
			if(hm.find(num[i]) == hm.end())//not find
				hm[num[i]] = 1;
			else
				hm[num[i]] = hm[num[i]]+1;//add the appear times
		}
		int max=0,flag=0;
		it = hm.begin();
		while(it != hm.end()){
			if(it->second > max){
				max = it -> second;
				flag = it -> first;
			}
			it++;
		}
		return flag;
    }
};