/*Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
Subscribe to see which companies asked this question

Hide Tags Binary Search Hash Table Two Pointers Sort
Show Similar Problems
*/
//basic way but seems sufficient
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0)
            return res;
        quickSort(nums1, 0, nums1.size() - 1);
        // show(nums1);
        quickSort(nums2, 0, nums2.size() - 1);
        // show(nums2);
        for(int i = 0; i < nums1.size(); i++) {
            if(binarySearch(nums2, nums1[i]) >= 0) {
                // cout<<"find: "<<nums1[i]<<endl;
                res.push_back(nums1[i]);
            }
            while(i < nums1.size() && nums1[i + 1] == nums1[i])
                i++;
        }
        return res;
        
    }
    
    void quickSort(vector<int>& nums, int left, int right) {
        if(left < right) {
            int i = partition(nums, left, right);
            quickSort(nums, left, i - 1);
            quickSort(nums, i + 1, right);
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int flag = nums[left];
        while(left < right) {
            while(left < right && nums[right] >= flag)  
                right--;
            nums[left] = nums[right];
            while(left < right && nums[left] <= flag)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = flag;
        return left;
    }
    int binarySearch(vector<int>& nums, int target) {
        // cout<<"target:"<<target<<endl;
        if(nums.size() == 0)
            return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(target < nums[mid])
                right = mid - 1;
            else if(target > nums[mid])
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    void show(vector<int>& n) {
        for(int i : n)
            cout<<i<<" ";
        cout<<endl;
    }
}; 

