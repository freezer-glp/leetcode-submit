/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Subscribe to see which companies asked this question

Hide Tags Array Binary Search
Show Similar Problems
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int flag = 0;
            int mid = (low + high) >> 1;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[high]) {
                //1,1,3,1�����������Ҫ���˺�벿�ֵ��ظ�
                while(high >= mid && nums[high] == nums[mid])
                    high --;
            }else if(nums[mid] < nums[high]) {
                //mid to high is in the right order
                if(nums[mid] < target && target <= nums[high]) {
                    while(mid < high && nums[mid + 1] == nums[mid]) {
                        //���ڴ����ظ���mid�ƶ�ʱ��Ҫ���˵��ظ�
                        mid ++;
                        flag = 1;//�˱�־��ʾ�����˹��˲���
                    }
                    if(flag == 1)//���˲����󣬵�ǰ�±��ƶ�������һλ��Ϊ��ͳһlow = mid + 1���������˵�Ҫ����һλ
                        mid --;
                    low = mid + 1;
                }else {
                    while(mid > low && nums[mid - 1] == nums[mid]) {
                        mid -- ;
                        flag = 1;
                    }
                    if(flag == 1)
                        mid ++;
                    high = mid - 1;
                }
            }else {
                //low to left is in the right order
                if(target >= nums[low] && target < nums[mid] ) {
                    while(mid > low && nums[mid - 1] == nums[mid]) {
                        mid --;
                        flag = 1;
                    }
                    if(flag == 1)
                        mid ++;
                    high = mid - 1;
                }else {
                    while(mid < high && nums[mid + 1] == nums[mid]) {
                        mid ++;
                        flag = 1;
                    }
                    if(flag == 1)
                        mid --;
                    low = mid + 1;
                }
            }
        }        
        return false;
    }
};