/*Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        if(k == 0)
            return ;
        for(int i = 1; i <= k; i++){
            int temp = nums.back();
            nums.pop_back();
            vector<int>::iterator it = nums.begin();
            nums.insert(it,temp);
        }
    }
};