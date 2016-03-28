/*Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Sort
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        quickSort(nums, 0, nums.size() - 1);
        cout<<endl;
        string res;
        if(nums[0] == 0)
            return (string)"0";
        for(int i : nums) {
            string tmp = to_string(i);
            res += tmp;
        }
        return res;
        
    }
    int partition(vector<int>& nums, int left, int right) {
        int flag = nums[left];
        while(left < right) {
            while(left < right && myCompare(nums[right], flag) == -1) //nums[right] <= flag
                right--;
            nums[left] = nums[right];
            while(left < right && myCompare(nums[left], flag) == 1) //nums[left] < flag
                left++;
            nums[right] = nums[left];
        }
        nums[left] = flag;
        return left;
    }
    void quickSort(vector<int>& nums, int left, int right) {
        if(left < right) {
            int index = partition(nums, left, right);
            quickSort(nums, left, index - 1);
            quickSort(nums, index + 1, right);
        }
    }
    int myCompare(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        int i = 0; int j = 0;
        string saf = sa + sb;
        string sbf = sb + sa;
        while(i < saf.size()) {
            if(saf[i] > sbf[i])
                return 1;
            else if(saf[i] < sbf[i])
                return -1;
            else
                i++;
        }
        return 1;
        
    }
};