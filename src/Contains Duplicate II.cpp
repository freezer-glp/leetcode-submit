/*Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

Hide Tags Array Hash Table
Show Similar Problems
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return false;
        map<int, int> m;
        map<int, int> :: iterator it;
        for(int i = 0; i <= nums.size(); i++){
            it = m.find(nums[i]);
            if(it != m.end()) { //find two same
                if(-abs(it -> second - i ) <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};