/*Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Hide Tags Array Hash Table
Show Similar Problems
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.empty())
            return false;
        map<int,int> m;
		for(int i = 0; i <= nums.size()-1; i++){
			if(m[nums[i]] == 0){
				m[nums[i]]++;
			}else if(m[nums[i]] == 1){
			    return true;
			}
		}
		return false;
    }
	
};

/*using sort to solve
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};
*/