/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

Subscribe to see which companies asked this question

Hide Tags Array Greedy
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
    //�ô�ͳ����һ�ɳ�ʱ�������ۺ�ѧ��һ��̰�ķ�
    //�������ȥ�ҳ�����⣬ֻҪ�ж��ܷ��ڵ��ﵱǰ��Զ����ǰ������Զ�ľ��뼴��
    int maxReach = 0;int i = 0;
    for(; i < nums.size() && i <= maxReach; i++)
        maxReach = max(i + nums[i], maxReach);
    return i == nums.size();//�ж�����Ƿ�maxreach���������޻���ֻ��������ѭ������˳������
        
    }
};