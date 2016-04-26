/*You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

Subscribe to see which companies asked this question

Hide Tags Divide and Conquer Binary Indexed Tree Segment Tree Binary Search Tree
Show Similar Problems
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        vector<int> res(n);
        if(n == 0)
            return res;
        for(int i = n - 1; i >= 0; i--) {
            int index = findIndex(nums[i], sorted);
            sorted.insert(sorted.begin() + index, nums[i]);
            res[i] = index;
        }
        return res;
    }
    int findIndex(int num, vector<int>& sorted) {
        if(sorted.size() == 0)
            return 0;
        int left = 0, right = sorted.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(sorted[mid] < num) 
                left = mid + 1;
            else//当小于等于时，都让right-1,可以保证多个相同元素，每次插入在最左边
                right = mid - 1;
        }
        //cout<<right<<endl;
        return left;
    }
};