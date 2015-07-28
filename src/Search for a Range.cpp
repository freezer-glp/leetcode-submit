/*Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 Array Binary Search
Show Similar Problems

*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
		int i = binarySearch(nums,target);
		if(i == -1){
		    v.push_back(-1);
		    v.push_back(-1);
		    return v;
		}
		int t = i;
		while(t >= 0 && nums[t] == target){
			t--;
		}
		v.push_back(t + 1);
		t = i;
		while(t <= nums.size() - 1 && nums[t] == target){
			t ++;
		}
		v.push_back(t - 1);

		return v;
    }
	
	int binarySearch(vector<int> &nums,int target){
		int low = 0;
		int top = nums.size()-1;
		int mid = (low + top ) / 2;
		while(low <= top){
			if(nums[mid] < target)
				low = mid + 1;
			else if(nums[mid] > target)
				top = mid - 1;
			else 
				return mid;
			mid = (low + top ) / 2;
		}
		return -1;
	}
};