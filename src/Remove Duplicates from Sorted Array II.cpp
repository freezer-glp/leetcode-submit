/*Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question

Hide Tags Array Two Pointers
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        int flag = nums[0];
        int count = 1;//计数器，记录一个数出现的次数
        int index = 1;//标识当前合法的位置的下标
        for(int i = 1; i <= len - 1; i++) {
            if(nums[i] == flag) {//当前的数重复出现过
                if(count < 2) {//满足<=2, 当前这个数合法
                    nums[index] = nums[i];//移到合法的位置去
                    index++;
                }
                count++;
            }else {//当前数第一次出现
                nums[index] = nums[i];
                flag = nums[i];
                count = 1;
                index++;
            }
            
        }
        return index;
        
        
    }
};