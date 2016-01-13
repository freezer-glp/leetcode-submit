//Remove Duplicates from Sorted Array
/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        queue<int > q;
        int flag;
        flag =  nums[0];
        int i = 1;
        while(i < nums.size()){
            if(nums[i] == flag){
                q.push(i);//将重复的位置放入队列中记录下来
                len--;
            }else{
                if(!q.empty()){
                    nums[q.front()] = nums[i];
                    q.pop();
                    q.push(i);
                    flag = nums[i];
                    //i--;
                }else
                    flag = nums[i];
            }
            i++;
        }
        
        return len;
    }
};