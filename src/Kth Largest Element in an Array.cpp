/*Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Divide and Conquer Heap
Show Similar Problems
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if(k > len)
            return -1;
        //先排序，再计算
        quickSort(nums, 0, len - 1);
        //
        int index = len - k;
        return nums[index];
    }
    void quickSort(vector<int>& nums, int low, int high) {
        // cout<<"low:"<<low<<" high:"<<high<<endl;
        if(nums.size() == 0 || low >= high)
            return ;
        int flag =  nums[low];
        int l = low, h = high;
        while(l < h) {
            while(l < h && nums[h] >= flag)
                h--;
            nums[l] = nums[h];
            while(l < h && nums[l] <= flag)
                l++;
            nums[h] = nums[l];
        }
        nums[l] = flag;
        // for(int a : nums)
        //     cout<<a<<" ";
        // cout<<endl;
        quickSort(nums, low, l - 1);
        quickSort(nums, l + 1, high);
        return;
    }
};