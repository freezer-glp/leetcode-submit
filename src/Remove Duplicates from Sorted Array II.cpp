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
        int count = 1;//����������¼һ�������ֵĴ���
        int index = 1;//��ʶ��ǰ�Ϸ���λ�õ��±�
        for(int i = 1; i <= len - 1; i++) {
            if(nums[i] == flag) {//��ǰ�����ظ����ֹ�
                if(count < 2) {//����<=2, ��ǰ������Ϸ�
                    nums[index] = nums[i];//�Ƶ��Ϸ���λ��ȥ
                    index++;
                }
                count++;
            }else {//��ǰ����һ�γ���
                nums[index] = nums[i];
                flag = nums[i];
                count = 1;
                index++;
            }
            
        }
        return index;
        
        
    }
};